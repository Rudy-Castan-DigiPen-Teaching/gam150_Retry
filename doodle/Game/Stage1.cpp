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

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter), player(0, 50, 50),
so1({doodle::random(0, Engine::GetWindow().GetSize().x), Engine::GetWindow().GetSize().y}, 40, 40),
so2({ doodle::random(0, Engine::GetWindow().GetSize().x), Engine::GetWindow().GetSize().y }, 40, 40),
so3({ doodle::random(0, Engine::GetWindow().GetSize().x), Engine::GetWindow().GetSize().y }, 40, 40),
on1(doodle::random(0, 4)), on2(doodle::random(0, 4)), on3(doodle::random(0, 4)){}

void Stage1::Load()
{
}

void Stage1::Draw()
{
	doodle::clear_background(100, 20, 100, 255);
	player.Draw();
	so1.Draw(on1);
	so2.Draw(on2);
	so3.Draw(on3);
}

void Stage1::Update()
{
	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true)
	{
	  Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
	player.Update(Retry::GameScenes::Stage1);
	so1.Update(on1);
	so2.Update(on2);
	so3.Update(on3);
}

void Stage1::Unload()
{
}