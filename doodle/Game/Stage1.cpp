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


Stage1::Stage1() : RolebackMenu(Retry::InputKey::Keyboard::Escape), StageStart(Retry::InputKey::Keyboard::Space), StageReload(Retry::InputKey::Keyboard::R), CheatKey(Retry::InputKey::Keyboard::Q),
StageNext(Retry::InputKey::Keyboard::Enter), UseItem(Retry::InputKey::Keyboard::E), player(95, floor, 50), hacker({ static_cast<double>(Engine::GetWindow().GetSize().x / 2) ,  static_cast<double>(Engine::GetWindow().GetSize().y) }), dropspeed(7),
GameStart(false), GameOver(false), GameClear(false), IsPreviousFileExist(false), isHindrance(false)
{
	prevScene = Retry::GameScenes::Village;
	time = 0;
	score = 0;
	heart = 3;
	file = 0;
	item = 0;
	hacker_timer = 0;
	sprite_num = -1;
}

void Stage1::Load()
{
	time = 0;
	score = 0;
	heart = 3;
	file = 0;
	item = 0;
	hacker_timer = 0;
	sprite_num = -1;
	GameStart = false;
	GameOver = false;
	GameClear = false;
	IsPreviousFileExist = false;
	isHindrance = false;

	player.Load();
	hacker.Load();
	
	sprite_file.Load("assets/folder.png");
	sprite_c_file.Load("assets/correct_file.png");
	sprite_in_file.Load("assets/incorrect_file.png");
	default_file.Load("assets/default_file.png");
	background.Load("assets/stage1_background.png");
	MousePointer.Load("assets/mouse_pointer.png", {0, 30});

	sprite_file1.Load("assets/folder_1insert.png");
	sprite_file2.Load("assets/folder_2insert.png");
	sprite_file3.Load("assets/folder_3insert.png");
	sprite_heart.Load("assets/Sprite-0001.png");
	
	sound.LoadSound("assets/drop_004.ogg"); // Insert correct file
	sound.LoadSound("assets/error_006.ogg");  // Insert incorrect file
	sound.LoadSound("assets/confirmation_002.ogg"); // make correct file
	sound.LoadSound("assets/error_003.ogg"); // Make incorrect file
	sound.LoadSound("assets/threeTone2.ogg"); // Input scissor
	sound.LoadSound("assets/dersuperanton__scissors-mc.ogg"); // use scissor
	music.openFromFile("assets/foolboymedia__video-game-land.ogg");


	sound.SetVolume(CorrectMakeFIle, 30);
	sound.SetVolume(InsertIncorrectFIle, 50);
	sound.SetVolume(InsertCorrectFIle, 30);
	sound.SetVolume(IncorrectMakeFile, 30);
	sound.SetVolume(scissorInput, 50);
	sound.SetVolume(scissorUse, 60);

	music.setLoop(true);
	music.setVolume(50);
	music.play();
}

void Stage1::Draw()
{
	background.Draw({0,0});
	player.Draw();
	sprite_file.Draw({50, 730});

	File_Draw(file);
	Heart_Draw(heart);

	MousePointer.Draw({ static_cast<double>(doodle::get_mouse_x()), static_cast<double>(doodle::get_mouse_y()) });

	if (IsPreviousFileExist == false)
	{
		default_file.Draw({ 200, 650 });
	}
	else if (IsPreviousFileExist == true)
	{
		switch (sprite_num)
		{
		case 0:
		case 1:
			sprite_c_file.Draw({ 200, 650 });
			break;
		case 2:
		case 3:
			sprite_in_file.Draw({ 200, 650 });
			break;
		default:
			break;
		}
	}



	for (int i = 0; i < data.size(); i++)
	{
		data[i].Draw_data();
	}

	for (int i = 0; i < scissor.size(); i++)
	{
		scissor[i].Draw_Item();
	}

	
	doodle::push_settings();
	doodle::set_font_size(20);
	doodle::draw_text(" :  " + std::to_string(file) + " / 5 ", 80, 710);
	doodle::draw_text("File input :          " + std::to_string(file_input.size()) + " / 5 ", 20, 620);
	doodle::draw_text("Scissor : " + std::to_string(item) + " / 1", 20, 570);
	doodle::pop_settings();
	
	if(GameStart == false && GameOver == false && GameClear == false)
	{	
		doodle::push_settings();
		doodle::set_font_size(30);
		doodle::set_fill_color(33, 255, 78);
		doodle::draw_text("<<Press Space bar to Start>>", 430, Engine::GetWindow().GetSize().y / 2.0 - 80.0);
		doodle::pop_settings();
	}
	else if (GameOver == true)
	{
		doodle::set_font_size(30);
		doodle::draw_text("Game Over!", 600, Engine::GetWindow().GetSize().y / 2.0);
	}
	else if (GameClear == true)
	{
		doodle::set_font_size(30);
		doodle::draw_text("Game Clear!", 600, Engine::GetWindow().GetSize().y / 2.0);
	}

	if (isHindrance == true)
	{
		hacker.Draw();
	}

}

void Stage1::Update(double)
{
#ifdef _DEBUG
	if (CheatKey.IsKeyReleased() == true)
	{
		GameClear = true;
		GameStart = false;
	}
#endif
	if (RolebackMenu.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}

	if(GameClear == true)
	{
		Engine::GetSceneManager().SetStageClear(Retry::GameScenes::Stage1);
		if (StageNext.IsKeyReleased() == true)
		{
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
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
		Engine::GetSceneManager().setGameOver(Retry::GameScenes::Stage1);
	}

	if(player.GetPosition().x - player.GetSize().x / 2 <= 0)
	{
		player.SetPosition({ static_cast<double>(player.GetSize().x) / 2.0 ,player.GetPosition().y });
	}
	if(player.GetPosition().x + player.GetSize().x / 2 >= static_cast<double>(Engine::GetWindow().GetSize().x))
	{
		player.SetPosition({ static_cast<double>(Engine::GetWindow().GetSize().x) - static_cast<double>(player.GetSize().x) / 2.0, player.GetPosition().y });
	}


	if(GameStart == true)
	{
		hacker_timer += doodle::DeltaTime;

		player.Update(Retry::GameScenes::Stage1);

		if (time % 45 == 0)
		{
			data_vector(dropspeed);
		}

		if (time % 900 == 0)
		{
			scissor_vector(dropspeed);
		}

		if (hacker_timer >= 12)
		{
			isHindrance = true;
		}

		if (isHindrance == true)
		{
			hacker.Update();
		}

		if (item == 1 && UseItem.IsKeyReleased() == true && isHindrance == true)
		{
			sound.PlaySound(scissorUse);
			scissor_input.clear();
			item = 0;
			hacker_timer = 0;
			hacker.SetPosition({ static_cast<double>(Engine::GetWindow().GetSize().x / 2) ,  static_cast<double>(Engine::GetWindow().GetSize().y) });
			isHindrance = false;
		}

		if(hacker.GetPosition().y <= -200.0)
		{
			hacker_timer = 0;
			hacker.SetPosition({ static_cast<double>(Engine::GetWindow().GetSize().x / 2) ,  static_cast<double>(Engine::GetWindow().GetSize().y) });
			isHindrance = false;
		}

		time++;

		for (int i = 0; i < scissor.size(); i++)
		{
			scissor[i].Update();

			if (player.CollideWith(scissor[i]) == true)
			{
				Engine::GetLogger().LogDebug("Scissor Collision!");
				scissor_input.push_back(scissor[i]);

				sound.PlaySound(scissorInput);

				for (Stage1_Item& s : scissor)
				{
					s.SetSpeed(dropspeed);
				}
				scissor.erase(scissor.begin() + i);
			}
		}

		for (int i = 0; i < data.size(); i++)
		{
			data[i].Update();
			
			if (data[i].Yisdown() == true)
			{
				data.erase(data.begin() + i);
			}

			if (player.CollideWith(data[i]) == true)
			{
				Engine::GetLogger().LogDebug("Collision!");
				
				IsPreviousFileExist = true;
				
				switch (data[i].GetNumbering())
				{
				case 0:
					sound.PlaySound(InsertCorrectFIle);
					Getnumber(data[i].GetNumbering());
					file_input.push_back(data[i].GetNumbering());
					break;
				case 1:
					sound.PlaySound(InsertCorrectFIle);
					Getnumber(data[i].GetNumbering());
					file_input.push_back(data[i].GetNumbering());
					break;
				case 2:
					sound.PlaySound(InsertIncorrectFIle);
					Getnumber(data[i].GetNumbering());
					file_input.push_back(data[i].GetNumbering());
					break;
				case 3:
					Getnumber(data[i].GetNumbering());
					sound.PlaySound(InsertIncorrectFIle);
					file_input.push_back(data[i].GetNumbering());
					break;
				}

				for (Stage1_Object& d : data)
				{
					d.SetSpeed(dropspeed);
				}
				data.erase(data.begin() + i);
			}
		}

		if (scissor_input.size() >= 1)
		{
			item = 1;
		}

		if (file_input.size() == 5)
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
		else if (file == 5)
		{
			GameStart = false;
			GameClear = true;
			music.pause();
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
	if (score == 5)
	{
		return true;
	}
	return false;
}

void Stage1::File_Draw(int file_number)
{
	switch (file_number)
	{
	case 1:
	case 2:
		sprite_file1.Draw({ 50, 730 });
		break;
	case 3:
	case 4:
		sprite_file2.Draw({ 50, 730 });
		break;
	case 5:
		sprite_file3.Draw({ 50, 730 });
		break;
	}
}

void Stage1::Heart_Draw(int heart_num)
{
	switch (heart_num)
	{
	case 1:
		sprite_heart.Draw({ 70, 530 });
		break;
	case 2:
		sprite_heart.Draw({ 70, 530 });
		sprite_heart.Draw({ 200, 530 });
		break;
	case 3:
		sprite_heart.Draw({ 70, 530 });
		sprite_heart.Draw({ 200, 530 });
		sprite_heart.Draw({ 330, 530 });
		break;
	}
}

void Stage1::data_vector(int speed)
{
	data.push_back(Stage1_Object({ doodle::random(100, Engine::GetWindow().GetSize().x - 100), Engine::GetWindow().GetSize().y + 100 }, doodle::random(0, 4), speed));
	data[data.size() - 1].Load();
}

void Stage1::scissor_vector(int speed)
{
	scissor.push_back(Stage1_Item({ doodle::random(100, Engine::GetWindow().GetSize().x - 100), Engine::GetWindow().GetSize().y + 100 }, speed));
	scissor[scissor.size() - 1].Load();
}


void Stage1::Getnumber(int number)
{
	sprite_num = number;
}


void Stage1::Unload()
{
	doodle::clear_background(165, 200, 255, 255);
	data.clear();
	scissor.clear();
	scissor_input.clear();
	music.stop();
}