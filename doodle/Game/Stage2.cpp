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

Stage2::Stage2() : StageNext(Retry::InputKey::Keyboard::Enter), player(0, 50, 50), stackedData(5) {}

void Stage2::Load()
{
	dataBoxes.clear();
	stackedData = 5;

	int num = 0;
	for (int i = 0; i < stackedData; ++i) 
	{
		num = doodle::random(3);
		switch (num) {
		case 0:
			dataBoxes.push_back(DataBox(DataBox::DataKinds::RED));
			break;
		case 1:
			dataBoxes.push_back(DataBox(DataBox::DataKinds::GREEN));
			break;
		case 2:
			dataBoxes.push_back(DataBox(DataBox::DataKinds::BLUE));
			break;
		}
	}
}

void Stage2::Update()
{
	/*
	* if (stackedData < 5)
	* dataBoxes.push_back(DataBox())
	*
	* for (int i = 0; i < dataBoxes.size(); ++i) {
	*	dataBoxes[i].Update();
	*	
	*	if (player.hasDataBox == false && dataBoxes[i].GetPosition().x == floor && player.CollisionWith(dataBoxes[i]) && Engine::GetMouseInput().IsMousePressed()) {
	*		dataBoxes[i].isStacked = false;
	*		player.hasDataBox = true;
	*	}
	* }
	* 
	* 
	* 
	*/

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

}
