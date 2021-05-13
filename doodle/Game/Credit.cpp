/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Credit.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 05/13/2021
-----------------------------------------------------------------*/

#include "Credit.h"
#include <doodle/drawing.hpp>
#include <string>

Credit::Credit(){}

void Credit::Load()
{
	int width = 150;
	int height = 60;

	buttons.push_back(Button("Back", math::vec2(Engine::GetWindow().GetSize().x - 200, Engine::GetWindow().GetSize().y * 0.1), width, height));
}

void Credit::Update(double)
{
	buttons[0].Update();

	if (buttons[0].isButtonPressed() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::MainMenu);
	}
}

void Credit::Draw()
{
	doodle::clear_background(0);
	doodle::draw_text("Producer : Yujin Park", 100, Engine::GetWindow().GetSize().y * 0.7);
	doodle::draw_text("Lead Designer : Yeonju Lee", 100, Engine::GetWindow().GetSize().y * 0.5);
	doodle::draw_text("Technical Director : Haeun Park", 100, Engine::GetWindow().GetSize().y * 0.3);
	buttons[0].Draw();
}

void Credit::Unload()
{
}

