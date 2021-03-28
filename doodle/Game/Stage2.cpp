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

Stage2::Stage2() : StageNext(Retry::InputKey::Keyboard::Enter) {}

void Stage2::Load() 
{
}

void Stage2::Update()
{
	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
	}
}

void Stage2::Unload()
{
}

void Stage2::Draw()
{
	doodle::clear_background(0, 0, 0, 255);

}