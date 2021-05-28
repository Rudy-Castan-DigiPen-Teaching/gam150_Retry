/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Village.cpp
Project: GAM150_Networker
Author: Yeongju Lee
Creation date: 05/06/2021
-----------------------------------------------------------------*/
#include "Village.h"
#include "../Engine/Engine.h"
#include <doodle/Input.hpp>
#include <doodle/drawing.hpp>

Village::Village() : shutDownKey(Retry::InputKey::Keyboard::Escape),
endingButton(math::vec2{ Engine::GetWindow().GetSize().x * 0.7, Engine::GetWindow().GetSize().y * 0.3 }, Retry::GameScenes::Ending)
{
	
}

void Village::Load()
{
	howToPlay_Security.Load("assets/htp_security.png");

	dataTransferHowToPlay.Load("assets/data_transfer_howtoplay.png");
	
	questButtons.push_back(QuestButton(math::vec2(Engine::GetWindow().GetSize().x - 150, Engine::GetWindow().GetSize().y * 0.8), Retry::GameScenes::Stage1));
	questButtons.push_back(QuestButton(math::vec2(Engine::GetWindow().GetSize().x - 150, Engine::GetWindow().GetSize().y * 0.2), Retry::GameScenes::Stage2));
	questButtons.push_back(QuestButton(math::vec2(Engine::GetWindow().GetSize().x - 150, Engine::GetWindow().GetSize().y * 0.5), Retry::GameScenes::Stage3));

	for (int i = 0; i < questButtons.size(); ++i)
	{
		if (Engine::GetSceneManager().StageCleared(questButtons[i].GetButtonStage()) == true)
		{
			questButtons[i].SetCleared(true);
		}
	}

	endingButton.SetCleared(true);
}

void Village::Update(double)
{
	if (shutDownKey.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
	for (int i = 0; i < questButtons.size(); ++i)
	{
		questButtons[i].Update();
		if (questButtons[i].GetButtonStage() != Retry::GameScenes::Stage2)
		{
			if (questButtons[i].IsButtonPressed() == true)
			{
				Engine::GetSceneManager().setNextScene(questButtons[i].GetButtonStage());
			}
		}
		else 
		{
			if (Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage1) == true && Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage3))
			{
				if (questButtons[i].IsButtonPressed() == true)
				{
					Engine::GetSceneManager().setNextScene(questButtons[i].GetButtonStage());
				}
			}
		}
	}
	endingButton.Update();
	if (Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage1) == true &&
		Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage2) == true &&
		Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage3) == true)
	{
		endingButton.SetCleared(false);
		if (endingButton.IsButtonPressed() == true)
		{
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Ending);
		}
	}
}

void Village::Unload()
{
	
}

void Village::Draw()
{
	doodle::clear_background(133, 230, 255);
	for (int i = 0; i < questButtons.size(); ++i)
	{
		questButtons[i].Draw();

		if (questButtons[i].IsMouseOn() == true)
		{
			switch (i)
			{
			case 0:
				doodle::push_settings();
				doodle::draw_rectangle(50, 100, 1000, 610);
				doodle::set_font_size(35);
				doodle::draw_text("Quest 1 - Collect data and create files!\n\nRetrieve the file!", 80, static_cast<double>(Engine::GetWindow().GetSize().y)- 200);
				doodle::pop_settings();
				break;
			case 1:
				dataTransferHowToPlay.Draw({ 50, 100 });
				break;
			case 2:
				doodle::push_settings();
				howToPlay_Security.Draw({ 50, 100 });
				//doodle::draw_rectangle(50, 100, 1000, 610);
				//doodle::set_font_size(35);
				//doodle::draw_text("Quest 3 - Kill the Virus!\n\nRetrieve the Pill!", 80, static_cast<double>(Engine::GetWindow().GetSize().y) - 200);
				doodle::pop_settings();
				break;
			}
		}
	}

	endingButton.Draw();
}

Village::QuestButton::QuestButton(math::vec2 pos, Retry::GameScenes stage) : position(pos), stage(stage), stageCleared(false)
{
	
}

bool Village::QuestButton::IsMouseOn()
{
	if (doodle::get_mouse_x() < position.x + width / 2 &&
		doodle::get_mouse_x() > position.x - width / 2 &&
		doodle::get_mouse_y() < position.y + height / 2 &&
		doodle::get_mouse_y() > position.y - height / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Village::QuestButton::IsButtonPressed()
{
	return buttonPressed;
}

void Village::QuestButton::Update()
{
	if (stageCleared == false && IsMouseOn() && Engine::GetMouseInput().IsMousePressed())
	{
		buttonPressed = true;
	}
	else
	{
		buttonPressed = false;
	}
}

void Village::QuestButton::Draw()
{
	doodle::push_settings();
	doodle::set_rectangle_mode(doodle::RectMode::Center);
	if (stageCleared == false)
	{
		if (IsMouseOn() == true)
		{
			doodle::set_fill_color(200);
		}
		else
		{
			doodle::set_fill_color(255);
		}
	}
	else
	{
		doodle::set_fill_color(100);
	}
	doodle::draw_rectangle(position.x, position.y, width, height);
	doodle::pop_settings();
}
