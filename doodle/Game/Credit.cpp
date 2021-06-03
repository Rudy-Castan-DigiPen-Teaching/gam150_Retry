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
	buttons.push_back(Button("assets/button_back.png", math::vec2(Engine::GetWindow().GetSize().x - 200, Engine::GetWindow().GetSize().y * 0.1)));
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
	doodle::push_settings();
	doodle::set_font_size(30);
	doodle::draw_text("President: Claude Comair", 100, Engine::GetWindow().GetSize().y * 0.9);
	doodle::draw_text("Instructor : KiKyeong Lim, David Ly", 100, Engine::GetWindow().GetSize().y * 0.8);
	doodle::draw_text("Teaching Assistant : Jina Hyun, Haewon Shon", 100, Engine::GetWindow().GetSize().y * 0.7);

	doodle::draw_text("Producer : Yujin Park", 100, Engine::GetWindow().GetSize().y * 0.6);
	doodle::draw_text("Lead Designer : Yeonju Lee", 100, Engine::GetWindow().GetSize().y * 0.5);
	doodle::draw_text("Technical Director : Haeun Park", 100, Engine::GetWindow().GetSize().y * 0.4);

	doodle::draw_text("Special Thanks for security stage bgm : dAmbient", 100, Engine::GetWindow().GetSize().y * 0.3);
	doodle::pop_settings();
	buttons[0].Draw();
}

void Credit::Unload()
{
}

