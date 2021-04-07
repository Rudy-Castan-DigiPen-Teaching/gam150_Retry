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


Stage3::Stage3() : StageNext(Retry::InputKey::Keyboard::Enter), Reload(Retry::InputKey::Keyboard::Escape),
player(Engine::GetWindow().GetSize() / 2.0, 50, 50) {}

void Stage3::Load()
{
	overlapseTime = 0;
	player.Load();
	bugs.push_back(Bug(NetworkLine::Middle));
	bugs.push_back(Bug(NetworkLine::Top, 10));
	bugs.push_back(Bug(NetworkLine::Bottom, 20));
	bugs.push_back(Bug(NetworkLine::Middle, 35, 2));
	bugs.push_back(Bug(NetworkLine::Top, 70, 35));
	bugs.push_back(Bug(NetworkLine::Bottom, 73, 35));
}

void Stage3::Unload()
{
	bugs.clear();
}

void Stage3::Update()
{
	overlapseTime += 0.1;

	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
	else if (Reload.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().ReloadScene();
	}

	player.Update(Retry::GameScenes::Stage3);

	for (size_t i = 0; i < bugs.size(); i++)
	{
		if (bugs[i].getAlive() == false)
		{
			bugs.erase(bugs.begin() + i);
		}
	}

	for (Bug& b : bugs)
	{
		if (b.getStartTime() <= overlapseTime && b.getAlive() == true)
		{
			b.Update(player);
			if (player.GetIsPlayerHitting() && b.CollideWith(player.GetAttackBox()))
			{
				b.HitByPlayer();
				Engine::GetLogger().LogDebug("Hit the Bug");
			}
			else if (b.CollideWith(player) && b.getHitThePlayer() == false) {
				player.HitByBug();
				b.HitThePlayer();
				Engine::GetLogger().LogDebug("Hit by Bug");
				b.setAlive(false);
			}
		}
	}

}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255);
	doodle::draw_text(std::to_string(player.GetLives()), 10, 200);
	doodle::push_settings();
	doodle::set_outline_width(7);
	doodle::set_outline_color(210, 253, 255);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.75, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.75);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.5, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.5);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.25, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.25);
	doodle::pop_settings();

	doodle::push_settings();
	player.Draw();

	for (Bug& b : bugs)
	{
		if (b.getStartTime() <= overlapseTime)
		{
			b.Draw();
		}
	}

	if (bugs.empty())
	{
		switch (player.GetLives())
		{
		case 3:
			doodle::draw_text("perfect clear!", 40, Engine::GetWindow().GetSize().y / 2);
			break;
		case 2:
		case 1:
			doodle::draw_text("clear!", 40, Engine::GetWindow().GetSize().y/2);
			break;
		case 0:
			doodle::draw_text("Fail", 40, Engine::GetWindow().GetSize().y / 2);

		}
	}

}
