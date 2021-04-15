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
#include "../Engine/Engine.h"


Stage1::Stage1() : StageStart(Retry::InputKey::Keyboard::Space), StageReload(Retry::InputKey::Keyboard::R),
StageNext(Retry::InputKey::Keyboard::Enter), player(170, 100, 50), s1(0, 10, 10, 0, 0), dropspeed(8)
{
}

void Stage1::Load()
{
	time = 0;
	score = 0;
	heart = 3;
	file = 0;
	sprite_num = -1;
	GameStart = false;
	GameOver = false;
	GameClear = false;
	IsPreviousFileExist = false;
	
	s1.revector(dropspeed);
	player.Load();
	s1.Load();
	sprite_file.Load("assets/file.png");
	sprite_c_file.Load("assets/correct_file.png");
	sprite_in_file.Load("assets/incorrect_file.png");
	default_file.Load("assets/default_file.png");

	sound.LoadSound("assets/drop_004.ogg"); // Insert correct file
	sound.LoadSound("assets/error_006.ogg");  // Insert incorrect file
	sound.LoadSound("assets/confirmation_002.ogg"); // make correct file
	sound.LoadSound("assets/error_003.ogg"); // Make incorrect file


	sound.SetVolume(CorrectMakeFIle, 30);
	sound.SetVolume(InsertIncorrectFIle, 50);
	sound.SetVolume(InsertCorrectFIle, 30);
	sound.SetVolume(IncorrectMakeFile, 30);
}

void Stage1::Draw()
{
	doodle::clear_background(165, 200, 255, 255);
	player.Draw();
	sprite_file.Draw({50, 750});
	
	s1.File_Draw(file);
	s1.Heart_Draw(heart);

	if (IsPreviousFileExist == false)
	{
		default_file.Draw({ 450, 680 });
	}
	else if (IsPreviousFileExist == true)
	{
		switch (sprite_num)
		{
		case 0:
		case 1:
			sprite_c_file.Draw({ 450, 680 });
			break;
		case 2:
		case 3:
			sprite_in_file.Draw({ 450, 680 });
			break;
		default:
			break;
		}
	}
	
	doodle::push_settings();
	doodle::set_font_size(30);
	doodle::draw_text(" :  " + std::to_string(file) + " / 3 ", 80, 720);
	doodle::draw_text("File previously put :          " + std::to_string(file_input.size()) + " / 3 ", 20, 650);
	if(GameStart == false && GameOver == false && GameClear == false)
	{
		doodle::draw_text("Move ZERO with the mouse and get the  \t!", 250, Engine::GetWindow().GetSize().y / 2.0 + 20.0);
		
		doodle::push_settings();
		doodle::set_fill_color(0, 100, 0);   //green
		doodle::draw_rectangle(1000, Engine::GetWindow().GetSize().y / 2.0 + 30, 40, 40);
		doodle::pop_settings();
		
		doodle::push_settings();
		doodle::set_fill_color(33, 255, 78);
		doodle::draw_text("<<Press Space bar to Start>>", 430, Engine::GetWindow().GetSize().y / 2.0 - 80.0);
		doodle::pop_settings();
	}
	else if (GameOver == true)
	{
		doodle::draw_text("Game Over!", 600, Engine::GetWindow().GetSize().y / 2.0);
	}
	else if (GameClear == true)
	{
		doodle::draw_text("Game Clear!", 600, Engine::GetWindow().GetSize().y / 2.0);
	}
	doodle::pop_settings();

	
	for (int i = 0; i < num.size(); i++)
	{
		num[i].Draw();
	}
}

void Stage1::Update()
{
	if(GameClear == true)
	{
		if (StageNext.IsKeyReleased() == true)
		{
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
		}
	}
	else if (StageStart.IsKeyReleased() == true)
	{
		GameStart = true;
	}
	else if (StageReload.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().ReloadScene();
	}

	if(GameOver == true)
	{
		if (StageReload.IsKeyReleased() == true)
		{
			Engine::GetSceneManager().ReloadScene();
		}
	}

	
	if(GameStart == true)
	{
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
				
				IsPreviousFileExist = true;
				
				switch (num[i].GetNumbering())
				{
				case 0:
					sound.PlaySound(InsertCorrectFIle);
					Getnumber(num[i].GetNumbering());
					file_input.push_back(num[i].GetNumbering());
					break;
				case 1:
					sound.PlaySound(InsertCorrectFIle);
					Getnumber(num[i].GetNumbering());
					file_input.push_back(num[i].GetNumbering());
					break;
				case 2:
					sound.PlaySound(InsertIncorrectFIle);
					Getnumber(num[i].GetNumbering());
					file_input.push_back(num[i].GetNumbering());
					break;
				case 3:
					Getnumber(num[i].GetNumbering());
					sound.PlaySound(InsertIncorrectFIle);
					file_input.push_back(num[i].GetNumbering());
					break;
				}
		/*		if (dropspeed <= 0)
				{
					dropspeed = 2;
				}*/

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
				IsPreviousFileExist = false;

				sound.PlaySound(CorrectMakeFIle);
			}
			else if (Identify_v() == false) {
				score = 0;
				file_input.clear();
				heart -= 1;
				IsPreviousFileExist = false;
				sound.PlaySound(IncorrectMakeFile);
			}
		}

		if (heart == 0)
		{
			GameOver = true;
			GameStart = false;
		}
		else if (file == 3)
		{
			GameStart = false;
			GameClear = true;
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

void Stage1::Getnumber(int number)
{
	sprite_num = number;
}


void Stage1::Unload()
{
	doodle::clear_background(165, 200, 255, 255);
	num.clear();
}