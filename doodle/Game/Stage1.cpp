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
#include <doodle/doodle.hpp>

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter), player(170, 100, 50), s1(0, 10, 10, 0){}

void Stage1::Load()
{
	s1.revector();
}

void Stage1::Draw()
{
	doodle::clear_background(165, 200, 255, 255);
	player.Draw();

	for (int i = 0; i < 5; i++)
	{
		num[i].Draw();
	}
}

void Stage1::Update()
{
	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true)
	{
	  Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
	player.Update(Retry::GameScenes::Stage1);

	for (int i = 0; i < 5; i++)
	{
		num[i].Update();
	}
}

void Stage1::Unload()
{
}