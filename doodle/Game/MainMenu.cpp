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
{}

void MainMenu::Load()
{
	int width = 150;
	int height = 60;

	buttons.push_back(Button("Stage 1", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.7), width, height));
	buttons.push_back(Button("Stage 2", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.5), width, height));
	buttons.push_back(Button("Stage 3", math::vec2(Engine::GetWindow().GetSize().x / 2, Engine::GetWindow().GetSize().y * 0.3), width, height));
}

void MainMenu::Update()
{
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
				Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage1);
				break;
			case 1:
				Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
				break;
			case 2:
				Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
				break;
			default:
				break;
			}
		}
	}
}

void MainMenu::Unload()
{
}

void MainMenu::Draw()
{
	doodle::clear_background(0, 0, 0);
	for (Button b : buttons)
	{
		b.Draw();
	}
}
