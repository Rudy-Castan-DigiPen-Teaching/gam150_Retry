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

#include <iostream>

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter), player(170, 100, 50), s1(0, 10, 10, 0, 0), dropspeed(10){
	time = 0;
	score = 0;
	heart = 3;
	file = 0;
}

void Stage1::Load()
{
	s1.revector(dropspeed);
}

void Stage1::Draw()
{
	doodle::clear_background(165, 200, 255, 255);
	player.Draw();

	doodle::push_settings();
	doodle::set_font_size(30);
	doodle::draw_text("Heart : " + std::to_string(heart), 100, 650);
	doodle::draw_text("File : " + std::to_string(file), 100, 600);
	doodle::draw_text("File contents ", 100, 550);
	doodle::pop_settings();
	for (int i = 0; i < num.size(); i++)
	{
		num[i].Draw();
	}
}

void Stage1::Update()
{

	if (StageNext.IsKeyReleased() == true || file == 3)
	{
	  Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
	else if (heart == 0)
	{
		Engine::GetSceneManager().Shutdown();
	}

	player.Update(Retry::GameScenes::Stage1);



	if (time % 20 == 0)
	{
		s1.revector(dropspeed);
	}

	time++;

	for (int i = 0; i < num.size(); i++)
	{
		num[i].Update();

		if (num[i].Yisdown() == true)
		{
			num.erase(num.begin() + i);
		}

		if (player.CollideWith(num[i]) == true)
		{
			Engine::GetLogger().LogDebug("Collision!");

			switch (num[i].GetNumbering())
			{
			case 0:
				// red
				//dropspeed -= 5;
				file_input.push_back(num[i].GetNumbering());
				break;
			case 1:
				// green
				//dropspeed -= 5;
				file_input.push_back(num[i].GetNumbering());
				break;
			case 2:
				// blue
				//dropspeed += 5;
				file_input.push_back(num[i].GetNumbering());
				break;
			case 3:
				// grey
				//dropspeed += 5;
				file_input.push_back(num[i].GetNumbering());
				break;
			}
			if (dropspeed <= 0)
			{
				dropspeed = 2;
			}

			for (Stage1_Object& n : num)
			{
				n.SetSpeed(dropspeed);
			}



			num.erase(num.begin() + i);
		}
	}
	
	if (file_input.size() == 3)
	{
		if (Identify_v() == true)
		{
			file_input.clear();
			score = 0;
			file += 1;
		}
		else if (Identify_v() == false) {
			score = 0;
			file_input.clear();
			heart -= 1;
		}
	}
	
}

bool Stage1::Identify_v()
{
	for (int i = 0; i < file_input.size(); i++)
	{
		switch (file_input[i])
		{
		case 0:
		case 1:
			score += 1;
			break; 
		case 2:
		case 3:
			score -= 1;
			break;
		}
	}
	if (score == 3)
	{
		return true;
	}
	return false;
}



void Stage1::Unload()
{
}