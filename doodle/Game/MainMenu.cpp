/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: MainMenu.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 04/15/2021
-----------------------------------------------------------------*/
#include "MainMenu.h"
#include <doodle/drawing.hpp>
#include <string>

MainMenu::MainMenu() : exitkey(Retry::InputKey::Keyboard::Escape)
{
	prevScene = Retry::GameScenes::MainMenu;
}

void MainMenu::Load()
{
	buttons.push_back(Button("assets/button_start.png", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.4)));
	buttons.push_back(Button("assets/button_credit.png", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.25)));
	buttons.push_back(Button("assets/button_option.png", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.1)));

	title.Load("assets/main_screen.png");

	music.openFromFile("assets/josefpres__rap-loops-001-simple-mix-long-loop-90-bpm.ogg");

	sound.LoadSound("assets/select_003.ogg");
	sound.SetVolume(click, 100);

	music.setLoop(true);
	music.setVolume(50);
	music.play();
}

void MainMenu::Update(double dt)
{
	for (Star& s : stars)
	{
		s.Update(dt);
	}

	if (exitkey.IsKeyReleased() == true)
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
				Engine::GetSceneManager().setNextScene(Retry::GameScenes::Story);
				break;
			case 1:
				sound.PlaySound(click);
				Engine::GetSceneManager().setNextScene(Retry::GameScenes::Credit);
				break;
			case 2:
				sound.PlaySound(click);
				//Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
				break;
			default:
				break;
			}
		}
	}
}

void MainMenu::Unload()
{
	music.stop();
}

void MainMenu::Draw()
{

	doodle::clear_background(0, 0, 0, 210);

	for (Star& s : stars)
	{
		s.Draw();
	}
	title.Draw(0);
	
	for (Button b : buttons)
	{
		b.Draw();
	}


}
