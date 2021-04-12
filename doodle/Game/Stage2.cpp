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
#include <doodle/drawing.hpp>
#include <doodle/random.hpp>

Stage2::Stage2() : StageReload(Retry::InputKey::Keyboard::Enter), StageNext(Retry::InputKey::Keyboard::Escape), player({200, Stage2::floor}, 50, 50), stackedData(1), currTransferNum(0) {}

void Stage2::Load()
{
	player.Load();
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
}

void Stage2::Update()
{
	
	if (stackedData < maxDataNum) {
		int num = doodle::random(3);

		dataBoxes.push_back(DataBox(static_cast<DataBox::DataType>(num)));
		++stackedData;
		Engine::GetLogger().LogDebug("New Data Stacked");
	}

	for (int i = 0; i < dataBoxes.size(); ++i) {
		
		if (player.hasDataBox == false && dataBoxes[i].GetPosition().y == floor && dataBoxes[i].isStacked == true &&
			player.CollideWith(dataBoxes[i]) == true && Engine::GetMouseInput().IsMousePressed() == true) 
		{
			dataBoxes[i].isStacked = false;
			player.hasDataBox = true;
			--stackedData;
		}

		if (dataBoxes[i].isStacked == false && dataBoxes[i].isOnBoard == false) {
			dataBoxes[i].SetPosition(math::vec2{ player.GetPosition().x + dataBoxes[i].GetSize().x, Stage2::floor });
		}

		for (int j = 0; j < dataBoard.size(); ++j) {
			if (dataBoxes[i].GetDataType() == dataBoard[j].GetDataType())
			{
				if (player.hasDataBox == true && player.CollideWith(dataBoard[j]) == true &&
					Engine::GetMouseInput().IsMousePressed() == true && dataBoxes[i].isOnBoard == false)
				{
					player.hasDataBox = false;
					dataBoxes[i].isOnBoard = true;
					dataBoard[j].AddCurrDataNum(1);
				}

				if (dataBoxes[i].isOnBoard == true && dataBoard[j].GetCurrDataNum() >= dataBoard[j].GetGoalDataNum())
				{
					dataBoard[j].reachedGoal = true;
				}
			}
		}
		
		dataBoxes[i].Update();
	}
	
	for (int i = 0; i < dataBoard.size(); ++i)
	{
		if (dataBoard[i].reachedGoal == true)
		{
			for (int j = 0; j < dataBoxes.size(); ++j)
			{
				if (dataBoxes[j].isOnBoard == true && dataBoard[i].GetDataType() == dataBoxes[j].GetDataType() && j < dataBoxes.size())
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

	player.Update();

	if (StageNext.IsKeyReleased() == true)
	{
		 Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
		//Engine::GetSceneManager().Shutdown();
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
	player.Draw();

	doodle::push_settings();
	doodle::draw_text(std::to_string(currTransferNum) + " Times Transfered", 200, 700);
	if (currTransferNum >= goalTranasferNum)
	{
		doodle::draw_text("Clear!!", doodle::Width / 2, doodle::Height / 2);
	}
	doodle::pop_settings();
}
