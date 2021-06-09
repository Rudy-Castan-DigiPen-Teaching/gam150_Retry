/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameOver.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/26/2021
-----------------------------------------------------------------*/
#include "GameOver.h"
#include "..\Engine/Engine.h"
#include <doodle/drawing.hpp>

GameOver::GameOver() : exitKey(Retry::InputKey::Keyboard::Escape)
{
	prevScene = Retry::GameScenes::Village;
}

void GameOver::Load()
{
	buttons.push_back(Button("assets/button_restart.png", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.35)));
	buttons.push_back(Button("assets/button_back.png", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.2)));

	sound.LoadSound("assets/select_003.ogg");
	sound.SetVolume(click, Retry::SoundOption::sfxVolume);
}


void GameOver::Update(double)
{
	if (exitKey.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].Update();

		if (buttons[i].isButtonPressed())
		{
			switch (i)
			{
			case 0:
				sound.PlaySound(click);
				Engine::GetSceneManager().setNextScene(prevScene);
				break;
			case 1:
				sound.PlaySound(click);
				Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
				break;
			default:
				break;
			}
		}
	}

}

void GameOver::Unload()
{
	
}

void GameOver::Draw()
{
	doodle::clear_background(0, 0, 0);
	doodle::push_settings();
	doodle::set_fill_color(255, 0, 0, 255);
	doodle::draw_text("Game Over", static_cast<double>(Engine::GetWindow().GetSize().x) / 2 - 150, static_cast<double>(Engine::GetWindow().GetSize().y) / 2);
	doodle::pop_settings();
	for (Button b : buttons)
	{
		b.Draw();
	}
}
