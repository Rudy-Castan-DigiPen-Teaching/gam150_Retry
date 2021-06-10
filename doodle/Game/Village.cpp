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
endingButton(math::vec2{ Engine::GetWindow().GetSize().x * 0.72, Engine::GetWindow().GetSize().y * 0.2 }, Retry::GameScenes::Ending, true)
{
	prevScene = Retry::GameScenes::MainMenu;
}

void Village::Load()
{
	background.Load("assets/quest_background.png");
	collecting_HowToPlay.Load("assets/data_collect_howtoplay.png");
	security_HowToPlay.Load("assets/security_howtoplay.png");
	dataTransfer_HowToPlay.Load("assets/data_transfer_howtoplay.png");
	helpme.Load("assets/helpme.png");
	
	items[static_cast<int>(Item::file)].Load("assets/clearfile_item.png");
	items[static_cast<int>(Item::pill)].Load("assets/pill_item.png");
	items[static_cast<int>(Item::box)].Load("assets/boxes_item.png");

	double win_x = static_cast<double>(Engine::GetWindow().GetSize().x);
	double win_y = static_cast<double>(Engine::GetWindow().GetSize().y);

	questButtons.push_back(QuestButton(math::vec2(win_x - 150, win_y * 0.8), Retry::GameScenes::Stage1, false));
	questButtons.push_back(QuestButton(math::vec2(win_x - 150, win_y * 0.5), Retry::GameScenes::Stage3, false));
	questButtons.push_back(QuestButton(math::vec2(win_x - 150, win_y * 0.2), Retry::GameScenes::Stage2, true));

	if (Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage1) == true &&
		Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage2) == true &&
		Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage3) == true)
	{
		endingButton.UnlockButton();
	}

	for (int i = 0; i < questButtons.size(); ++i)
	{
		if (Engine::GetSceneManager().StageCleared(questButtons[i].GetButtonStage()) == true)
		{
			questButtons[i].SetCleared(true);
		}
		if (questButtons[i].IsLocked() == true && Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage1) == true && Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage3))
		{
			questButtons[i].UnlockButton();
		}
	}

	sound.LoadSound("assets/select_003.ogg");
	sound.SetVolume(click, Retry::SoundOption::sfxVolume);
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
		if (questButtons[i].IsButtonPressed() == true && questButtons[i].IsLocked() == false)
		{
			sound.PlaySound(click);
			Engine::GetSceneManager().setNextScene(questButtons[i].GetButtonStage());
		}
	}
	endingButton.Update();
	if (Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage1) == true &&
		Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage2) == true &&
		Engine::GetSceneManager().StageCleared(Retry::GameScenes::Stage3) == true)
	{
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
	background.Draw({ 0,0 });
	for (int i = 0; i < questButtons.size(); ++i)
	{
		questButtons[i].Draw();

		if (questButtons[i].IsMouseOn() == true)
		{
			switch (i)
			{
			case 0:
				collecting_HowToPlay.Draw({ 50, 100 });
				break;
			case 1:
				security_HowToPlay.Draw({ 50, 100 });
				break;
			case 2:
				dataTransfer_HowToPlay.Draw({ 50, 100 });
				break;
			}
		}
	}

	if (endingButton.IsMouseOn() == true)
	{
		helpme.Draw({ 50,100 });

		for (int i = 0; i < static_cast<int>(Item::count); i++)
		{
			doodle::push_settings();
			if (!questButtons[i].GetCleared())
			{
				doodle::set_tint_color(72);
			}
			items[i].Draw({ Engine::GetWindow().GetSize().x * (0.1 + i * 0.15), Engine::GetWindow().GetSize().y * 0.3 });
			doodle::pop_settings();
		}
	}

	endingButton.Draw();

}

Village::QuestButton::QuestButton(math::vec2 pos, Retry::GameScenes stage, bool isLocked) : position(pos), stage(stage), stageCleared(false), isLocked(isLocked)
{
	posibleTexture.Load("assets/questbutton_possible.png");
	lockedTexture.Load("assets/questbutton_lock.png");
	completeTexture.Load("assets/questbutton_complete.png");

	width = posibleTexture.getSize().x;
	height = posibleTexture.getSize().y;
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
		if (isLocked == true)
		{
			lockedTexture.Draw(position - math::vec2{ width, height } / 2);
		}
		else
		{
			posibleTexture.Draw(position - math::vec2{ width, height } / 2);
		}
	}
	else
	{
		completeTexture.Draw(position - math::vec2{ width, height } / 2);
	}
	doodle::pop_settings();
}

Village::EndingButton::EndingButton(math::vec2 pos, Retry::GameScenes stage, bool isLocked) : QuestButton(pos, stage, isLocked)
{
	posibleTexture.Load("assets/administrator_standing.png");
	lockedTexture.Load("assets/administrator_standing.png");
	completeTexture.Load("assets/administrator_standing.png");

	width = posibleTexture.getSize().x;
	height = posibleTexture.getSize().y;
}
