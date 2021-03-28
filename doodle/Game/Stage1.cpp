/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage1.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#include "Stage1.h"
#include <doodle/drawing.hpp>

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter),
player(0,50,50){}

void Stage1::Load()
{
}

void Stage1::Draw()
{
	doodle::clear_background(100, 20, 100, 255);
	player.Draw();
}

void Stage1::Update()
{
	if (StageNext.IsKeyReleased() == true)
	{
	  Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
	player.Update();
}

void Stage1::Unload()
{
}