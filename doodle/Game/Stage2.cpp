/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage2.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#include "Stage2.h"
#include "../Engine/Engine.h"
#include <doodle/drawing.hpp>
#include <doodle/random.hpp>

Stage2::Stage2() : RolebackMenu(Retry::InputKey::Keyboard::Escape), StageReload(Retry::InputKey::Keyboard::R), StageNext(Retry::InputKey::Keyboard::Enter), StageStart(Retry::InputKey::Keyboard::Space),
CheatKey(Retry::InputKey::Keyboard::Q),
hacker(math::vec2(Engine::GetWindow().GetSize().x, Stage2::floor)), player({ 200, Stage2::floor }, 93, 93, &hacker),
stackedData(1), currTransferNum(0), timer(0), stageStarted(false), stageCleared(false)
{
	prevScene = Retry::GameScenes::Village;
}

void Stage2::Load()
{
	background.Load("assets/stage2_background.png");
	
	sound.LoadSound("assets/tone1.ogg");
	sound.LoadSound("assets/powerUp7.ogg");
	sound.LoadSound("assets/pepSound1.ogg");
	sound.LoadSound("assets/phaserUp5.ogg");

	sound.SetVolume(StackBox, 30);
	sound.SetVolume(TransferData, 30);
	sound.SetVolume(StealData, 30);
	sound.SetVolume(RefillData, 30);
	
	player.Load();
	hacker.Load();
	dataBoxes.clear();
	dataBoard.clear();
	stackedData = 1;
	currTransferNum = 0;

	timer = 0;
	stageStarted = false;
	stageCleared = false;
	
	int num = 0;
	for (int i = 0; i < stackedData; ++i) 
	{
		num = doodle::random(3);
		dataBoxes.push_back(DataBox(static_cast<DataBox::DataType>(num)));
	}

	for (int i = 0; i <= static_cast<int>(DataBox::DataType::BLUE); ++i)
	{
		dataBoard.push_back(DataBoard(Stage2::floor, static_cast<DataBox::DataType>(i)));
	}
}

void Stage2::Update(double dt)
{
#ifdef _DEBUG
	if (CheatKey.IsKeyReleased() == true)
	{
		stageCleared = true;
	}
#endif
	if (stageCleared == true)
	{
		Engine::GetSceneManager().SetStageClear(Retry::GameScenes::Stage2);
	}
	if (timer >= timeLimit)
	{
		Engine::GetSceneManager().setGameOver(Retry::GameScenes::Stage2);
	}
	if (RolebackMenu.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}
	if (StageReload.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().ReloadScene();
	}
	if (stageCleared == true && StageNext.IsKeyReleased())
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}
	
	if (currTransferNum == goalTranasferNum)
	{
		stageCleared = true;
	}
	
	if (stageStarted == false && StageStart.IsKeyReleased() == true)	// Start Game after mouse is released
	{
		stageStarted = true;
	}
	else if (stageStarted == true && stageCleared == false)	// Game has started, and stage has not been cleared
	{
		timer += dt;	// Update timer

		if (timer > timeLimit)
		{
			timer = timeLimit;
		}
		else
		{
			if (timer > timeLimit - 10)	// if left time is 10 seconds
			{
				player.SpeedUp();
			}
			
			if (stackedData < maxDataNum)
			{
				sound.PlaySound(RefillData);
				int num = doodle::random(3);

				dataBoxes.push_back(DataBox(static_cast<DataBox::DataType>(num)));
				++stackedData;
				Engine::GetLogger().LogDebug("New Data Stacked");
			}
			for (int i = 0; i < dataBoxes.size(); ++i) 
			{
				dataBoxes[i].Update();
				if (player.hasDataBox == false && dataBoxes[i].GetPosition().y == floor && dataBoxes[i].isStacked == true &&
					player.CollideWith(dataBoxes[i]) == true && Engine::GetMouseInput().IsMousePressed() == true)
				{
					dataBoxes[i].isStacked = false;
					player.hasDataBox = true;
					--stackedData;
				}
				
				if (dataBoxes[i].isStacked == false && dataBoxes[i].isOnBoard == false && dataBoxes[i].isStolen == false && player.hasDataBox == true) 
				{
					dataBoxes[i].SetPosition(math::vec2{ player.GetPosition().x + 62 + dataBoxes[i].GetSize().x / 2, player.GetPosition().y + 27 });
				}

				for (int j = 0; j < dataBoard.size(); ++j) {
					if (dataBoxes[i].GetDataType() == dataBoard[j].GetDataType())
					{
						if (dataBoxes[i].isOnBoard == true)
						{
							if (hacker.hasDataBox == false) 
							{
								if (hacker.IsAppeard() == true && hacker.targettingBox == false && dataBoxes[i].isTargetted == false)
								{
									hacker.SetBoxPosition(dataBoxes[i].GetPosition());
									hacker.targettingBox = true;
									dataBoxes[i].isTargetted = true;
								}

								if (dataBoxes[i].isTargetted == true && hacker.targettingBox == true && hacker.CollideWith(dataBoxes[i]))
								{
									sound.PlaySound(StealData);
									hacker.hasDataBox = true;
									dataBoxes[i].isOnBoard = false;
									dataBoxes[i].isStolen = true;
									dataBoard[j].AddCurrDataNum(-1);
								}
							}
						}
						else
						{
							if (dataBoxes[i].isTargetted == true && dataBoxes[i].isStolen == true)
							{
								dataBoxes[i].SetPosition(math::vec2(hacker.GetPosition().x + dataBoxes[i].GetSize().x, hacker.GetPosition().y));
							}

							if (dataBoxes[i].isStacked == false && player.hasDataBox == true && 
								player.CollideWith(dataBoard[j]) == true && 
								(dataBoxes[i].GetPosition().x - static_cast<double>(dataBoxes[i].GetSize().x)/2 > dataBoard[j].GetPosition().x - static_cast<double>(dataBoard[j].GetSize().x)/2 &&
								dataBoxes[i].GetPosition().x + static_cast<double>(dataBoxes[i].GetSize().x)/2 < dataBoard[j].GetPosition().x + static_cast<double>(dataBoard[j].GetSize().x)/2) &&
								Engine::GetMouseInput().IsMousePressed() == true && dataBoxes[i].isStolen == false)
							{
								sound.PlaySound(StackBox);
								player.hasDataBox = false;
								dataBoxes[i].isOnBoard = true;
								dataBoxes[i].SetPosition(math::vec2(dataBoxes[i].GetPosition().x, dataBoard[j].GetPosition().y + dataBoard[j].GetSize().y));
								dataBoard[j].AddCurrDataNum(1);
							}
						}
						if (dataBoxes[i].isOnBoard == true && dataBoard[j].GetCurrDataNum() >= dataBoard[j].GetGoalDataNum())
						{
							dataBoard[j].reachedGoal = true;
						}
					}
				}				
				if (dataBoxes[i].isStolen == true && hacker.GetPosition().x >= Engine::GetWindow().GetSize().x)
				{
					dataBoxes.erase(dataBoxes.begin() + i);
					--i;
				}
			}
			
			for (int i = 0; i < dataBoard.size(); ++i)
			{
				if (dataBoard[i].reachedGoal == true)
				{
					for (int j = 0; j < dataBoxes.size(); ++j)
					{
						if (dataBoxes[j].isOnBoard == true && dataBoard[i].GetDataType() == dataBoxes[j].GetDataType())
						{
							if (dataBoxes[j].isTargetted == true && hacker.IsAppeard() == true)
							{
								hacker.hasDataBox = true;
							}
							dataBoxes.erase(dataBoxes.begin() + j);
							Engine::GetLogger().LogDebug("Data box in vector erased");
							--j;
						}
					}
					sound.PlaySound(TransferData);
					++currTransferNum;
					dataBoard[i].reachedGoal = false;
				}
				dataBoard[i].Update();
			}
			hacker.Update();
			player.Update();
		}
	}
}

void Stage2::Unload()
{
	dataBoxes.clear();
	dataBoard.clear();
}

void Stage2::Draw()
{
	background.Draw({0, 0});
	for (int i = 0; i < dataBoard.size(); ++i) {
		dataBoard[i].Draw();
	}
	for (int i = 0; i < dataBoxes.size(); ++i) {
		if (dataBoxes[i].isOnBoard == true || dataBoxes[i].isStacked == true || dataBoxes[i].isStolen == false)
		{
			dataBoxes[i].Draw();
		}
	}
	for (int i = 0; i < dataBoxes.size(); ++i)
	{
		if (dataBoxes[i].isOnBoard == false && dataBoxes[i].isStacked == false || dataBoxes[i].isStolen == true)
		{
			dataBoxes[i].Draw();
		}
	}
	hacker.Draw();
	player.Draw();

	doodle::push_settings();
	doodle::set_font_size(40);
	if (stageStarted == false && stageCleared == false)
	{
		doodle::draw_text("Press Space Bar to Start", 370, doodle::Height / 2);
	}
	if (stageCleared == true)
	{
		doodle::draw_text("Clear!!", doodle::Width / 2.0, doodle::Height / 2.0);
	}
	doodle::pop_settings();
	doodle::push_settings();
	doodle::set_font_size(40);
	if (timer > timeLimit - 10)
	{
		doodle::set_fill_color(255, 0, 0);
	}
	doodle::draw_text(std::to_string(currTransferNum) + " Times Transfered", 490, Engine::GetWindow().GetSize().y * 0.8);
	doodle::draw_text("Time : " + std::to_string(timeLimit - static_cast<int>(timer)), 490, Engine::GetWindow().GetSize().y * 0.7);
	doodle::pop_settings();
}
