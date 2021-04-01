/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage3.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#include <doodle/drawing.hpp>
#include "Stage3.h"
#include "../Engine/Engine.h" // GetLogger


Stage3::Stage3() : StageNext(Retry::InputKey::Keyboard::Escape),
player(Engine::GetWindow().GetSize() / 2.0, 50, 50) {}

void Stage3::Load()
{
}

void Stage3::Update()
{
	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}

	player.Update(Retry::GameScenes::Stage3);
}

void Stage3::Unload()
{
}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255);

	doodle::push_settings();
	doodle::set_outline_width(7);
	doodle::set_outline_color(210, 253, 255);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.75, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.75);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.5, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.5);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.25, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.25);
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_rectangle_mode(doodle::RectMode::Center);
	player.Draw();
	doodle::pop_settings();
}
