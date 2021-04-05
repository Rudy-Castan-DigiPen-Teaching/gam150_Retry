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

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter), player(170, 100, 50), s1(0, 10, 10, 0){
	time = 0;
	score = 0;
	heart = 3;
	file = 0;
}

void Stage1::Load()
{
	s1.revector();
}

void Stage1::Draw()
{
	doodle::clear_background(165, 200, 255, 255);
	player.Draw();

	doodle::push_settings();
	doodle::set_font_size(30);
	doodle::draw_text("score : " + std::to_string(score), 100, 700);
	doodle::draw_text("Heart : " + std::to_string(heart), 100, 650);
	doodle::draw_text("File : " + std::to_string(file), 100, 600);
	doodle::pop_settings();
	for (int i = 0; i < num.size(); i++)
	{
		num[i].Draw();
	}
}

void Stage1::Update()
{

	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true || file == 3)
	{
	  Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
	else if (heart == 0)
	{
		Engine::GetSceneManager().Shutdown();
	}
	player.Update(Retry::GameScenes::Stage1);

	if (time % 55 == 0)
	{
		s1.revector();
	}

	time++;

	for (int i = 0; i < num.size(); i++)
	{
		num[i].Update();
	}

	for (int i = 0; i < num.size(); i++)
	{
		if (num[i].Yisdown() == true)
		{
			num.erase(num.begin() + i);
		}
	}
		
	for (int i = 0; i < num.size(); i++)
	{
		if (player.CollideWith(num[i]) == true)
		{
			Engine::GetLogger().LogDebug("Collision!");

			switch (num[i].GetNumbering())
			{
			case 0:
				score += 1;     // red
				Engine::GetLogger().LogEvent("Im Red +1");
				break;
			case 1:
				score += 2;     // green
				Engine::GetLogger().LogEvent("Im green +2");
				break;
			case 2:
				score -= 3;     // blue
				heart -= 1;
				Engine::GetLogger().LogEvent("Im blue -3");
				break;
			case 3:
				score -= 4;     // grey
				heart -= 1;
				Engine::GetLogger().LogEvent("Im grey -4");
				break;
			}
			num.erase(num.begin() + i);
		}
	}

	if (score >= 10)
	{
		score -= 10;
		file += 1;
	}
}

void Stage1::Unload()
{
}