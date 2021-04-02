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

Stage2::Stage2() : StageNext(Retry::InputKey::Keyboard::Enter), player({0, Stage2::floor}, 50, 50), stackedData(1) {}

void Stage2::Load()
{
	player.Load();
	dataBoxes.clear();
	stackedData = 1;

	int num = 0;
	DataBox::DataType dataType = DataBox::DataType::RED;
	for (int i = 0; i < stackedData; ++i) 
	{
		num = doodle::random(3);
		switch (num) {
		case 0:
			dataType = DataBox::DataType::RED;
			break;
		case 1:
			dataType = DataBox::DataType::GREEN;
			break;
		case 2:
			dataType = DataBox::DataType::BLUE;
			break;
		}
		dataBoxes.push_back(DataBox(dataType, player));
	}
}

void Stage2::Update()
{
	
	if (stackedData < maxDataNum) {
		DataBox::DataType dataType = DataBox::DataType::RED;
		int num = doodle::random(3);
		switch(num) {
		 case 0:
			dataType = DataBox::DataType::RED;
			break;
		 case 1:
			dataType = DataBox::DataType::GREEN;
			break;
		 case 2:
			dataType = DataBox::DataType::BLUE;
			break;
		}
		dataBoxes.push_back(DataBox(dataType, player));
	}
	
	for (int i = 0; i < dataBoxes.size(); ++i) {
		dataBoxes[i].Update();

		if (player.hasDataBox == false && dataBoxes[i].GetPosition().y == floor && 
			player.CollideWith(dataBoxes[i]) == true && Engine::GetMouseInput().IsMousePressed() == true) 
		{
			dataBoxes[i].isStacked = false;
			player.hasDataBox = true;
		}
	}
	
	
	
	

	player.Update(Retry::GameScenes::Stage2);

	if (StageNext.IsKeyReleased() == true)
	{
		// Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
		Engine::GetSceneManager().Shutdown();
	}
}

void Stage2::Unload()
{
}

void Stage2::Draw()
{
	doodle::clear_background(0, 0, 0, 255);
	for (int i = 0; i < dataBoxes.size(); ++i) {
		dataBoxes[i].Draw();
	}
	player.Draw();
}
