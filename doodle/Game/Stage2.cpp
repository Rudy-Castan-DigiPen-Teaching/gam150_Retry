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
player({200, Stage2::floor}, 50, 50), hacker(math::vec2(Engine::GetWindow().GetSize().x, Stage2::floor)),
stackedData(1), currTransferNum(0), timer(0), gameStarted(false), stageCleared(false) {}

void Stage2::Load()
{
	sound.LoadSound("assets/tone1.ogg");
	sound.LoadSound("assets/powerUp7.ogg");
	sound.LoadSound("assets/pepSound1.ogg");
	sound.LoadSound("assets/phaserUp5.ogg");

	sound.SetVolume(StackBox, 30);
	sound.SetVolume(TransferData, 30);
	sound.SetVolume(SteelData, 30);
	sound.SetVolume(RefillData, 30);
	
	player.Load();
	hacker.Load();
	dataBoxes.clear();
	dataBoard.clear();
	stackedData = 1;
	currTransferNum = 0;

	int num = 0;
	for (int i = 0; i < stackedData; ++i) 
	{
		num = doodle::random(3);
		dataBoxes.push_back(DataBox(static_cast<DataBox::DataType>(num)));
	}

	for (int i = 0; i < static_cast<int>(DataBox::DataType::BLUE) + 1; ++i)
	{
		dataBoard.push_back(DataBoard(Stage2::floor, static_cast<DataBox::DataType>(i)));
	}

	timer = 0;
	gameStarted = false;
	stageCleared = false;
}

void Stage2::Update()
{
	if (gameStarted == false && StageStart.IsKeyReleased() == true )	// Start Game after mouse is released
	{
		gameStarted = true;
	}
	else if (gameStarted == true && stageCleared == false)	// Game has started, and stage has not been cleared
	{
		timer += doodle::DeltaTime;	// Update timer
		
		if (timer <= timeLimit)	// If time is not over
		{
			if (timer > timeLimit - 10.0)	// if left time is 10 minutes
			{
				player.SetSpeed(10);
			}
			
			if (stackedData < maxDataNum)
			{
				int num = doodle::random(3);

				dataBoxes.push_back(DataBox(static_cast<DataBox::DataType>(num)));
				++stackedData;
				Engine::GetLogger().LogDebug("New Data Stacked");
			}

			for (int i = 0; i < dataBoxes.size(); ++i) 
			{
				// player take stacked box
				if (player.hasDataBox == false && dataBoxes[i].GetPosition().y == floor && dataBoxes[i].isStacked == true &&
					player.CollideWith(dataBoxes[i]) == true && Engine::GetMouseInput().IsMousePressed() == true)
				{
					dataBoxes[i].isStacked = false;
					player.hasDataBox = true;
					--stackedData;
				}
				
				if (dataBoxes[i].isStacked == false && dataBoxes[i].isOnBoard == false && dataBoxes[i].isStolen == false && player.hasDataBox == true) 
				{
					dataBoxes[i].SetPosition(math::vec2{ player.GetPosition().x + dataBoxes[i].GetSize().x, Stage2::floor });
				}

				for (int j = 0; j < dataBoard.size(); ++j) {
					if (dataBoxes[i].GetDataType() == dataBoard[j].GetDataType())
					{
						if (dataBoxes[i].isOnBoard == true)
						{
							if (hacker.IsAppeard() == true && hacker.hasDataBox == false && hacker.targettingBox == false && dataBoxes[i].isTargetted == false)
							{
								hacker.SetBoxPosition(dataBoxes[i].GetPosition());
								hacker.targettingBox = true;
								dataBoxes[i].isTargetted = true;
							}

							if (dataBoxes[i].isTargetted == true && hacker.targettingBox == true && hacker.hasDataBox == false && hacker.CollideWith(dataBoxes[i]))
							{
								hacker.hasDataBox = true;
								dataBoxes[i].isOnBoard = false;
								dataBoxes[i].isStolen = true;
								dataBoard[j].AddCurrDataNum(-1);
							}
						}
						else
						{
							if (dataBoxes[i].isTargetted == true && dataBoxes[i].isStolen == true)
							{
								dataBoxes[i].SetPosition(math::vec2(hacker.GetPosition().x + dataBoxes[i].GetSize().x, hacker.GetPosition().y));
							}
						}
						
						if (dataBoxes[i].isStacked == false && player.hasDataBox == true && player.CollideWith(dataBoard[j]) == true &&
							Engine::GetMouseInput().IsMousePressed() == true && dataBoxes[i].isOnBoard == false && dataBoxes[i].isStolen == false)
						{
							player.hasDataBox = false;
							dataBoxes[i].isOnBoard = true;
							dataBoxes[i].UpdatePosition(math::vec2(0, dataBoard[j].GetSize().y));
							dataBoard[j].AddCurrDataNum(1);
						}

						
						if (dataBoxes[i].isOnBoard == true && dataBoard[j].GetCurrDataNum() >= dataBoard[j].GetGoalDataNum())
						{
							dataBoard[j].reachedGoal = true;
						}
					}
				}

				dataBoxes[i].Update();
				
				if (dataBoxes[i].isStolen == true && hacker.GetPosition().x > Engine::GetWindow().GetSize().x)
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
							dataBoxes.erase(dataBoxes.begin() + j);
							Engine::GetLogger().LogDebug("Data box in vector erased");
							--j;
						}
					}

					++currTransferNum;
					dataBoard[i].reachedGoal = false;
				}
				dataBoard[i].Update();


			}
			
			if (currTransferNum >= goalTranasferNum)
			{
				stageCleared = true;
			}
			
			hacker.Update();
			player.Update();
		}

		if (timer > timeLimit)
		{
			timer = timeLimit;
		}

	}

	if (RolebackMenu.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::MainMenu);
	}
	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
		// Engine::GetSceneManager().Shutdown();
	}
	if (StageReload.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().ReloadScene();
	}
}

void Stage2::Unload()
{
}

void Stage2::Draw()
{
	doodle::clear_background(0, 0, 0, 255);
	for (int i = 0; i < dataBoard.size(); ++i) {
		dataBoard[i].Draw();
	}
	for (int i = 0; i < dataBoxes.size(); ++i) {
		dataBoxes[i].Draw();
	}
	hacker.Draw();
	player.Draw();

	doodle::push_settings();
	doodle::set_font_size(40);
	doodle::draw_text(std::to_string(currTransferNum) + " Times Transfered", Engine::GetWindow().GetSize().x * 0.05, Engine::GetWindow().GetSize().y * 0.9);
	if (gameStarted == false)
	{
		doodle::draw_text("Press Space Bar to Start", 370, doodle::Height / 2);
	}
	if (stageCleared == true)
	{
		doodle::draw_text("Clear!!", doodle::Width / 2.0, doodle::Height / 2.0);
	}
	else if (timer >= timeLimit)
	{
		doodle::draw_text("Game Over", doodle::Width / 2.0, doodle::Height / 2.0);
	}
	doodle::pop_settings();

	
	doodle::push_settings();
	doodle::set_font_size(40);
	if (timer > timeLimit - 10)
	{
		doodle::set_fill_color(255, 0, 0);
	}
	doodle::draw_text("Time : " + std::to_string(timeLimit - static_cast<int>(timer)), Engine::GetWindow().GetSize().x * 0.8, Engine::GetWindow().GetSize().y * 0.9);
	doodle::pop_settings();
}
