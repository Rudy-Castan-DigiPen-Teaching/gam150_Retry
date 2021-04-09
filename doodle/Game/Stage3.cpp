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
	sound.LoadSound("assets/error_003.ogg");
	sound.SetVolume(killBug, 20);
	gameOver = false;
	overlapseTime = 0;
	player.Load();
	bugs.push_back(Bug(NetworkLine::Middle));
	bugs.push_back(Bug(NetworkLine::Top, 10));
	bugs.push_back(Bug(NetworkLine::Bottom, 20));
	bugs.push_back(Bug(NetworkLine::Middle, 35, 2));
	bugs.push_back(Bug(NetworkLine::Top, 70, 19));
	bugs.push_back(Bug(NetworkLine::Bottom, 73, 19));

	for (Bug& bug : bugs)
	{
		bug.Load();
	}
}

void Stage3::Unload()
{
	doodle::clear_background(100, 100, 255);
	bugs.clear();
}

void Stage3::Update()
{
	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
	else if (Reload.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().ReloadScene();
	}
	if (!gameOver) {
		overlapseTime += 0.1;
		player.Update(Retry::GameScenes::Stage3);

		for (Bug& bug : bugs)
		{
			if (bug.getStartTime() <= overlapseTime && bug.getAlive() == true)
			{
				bug.Update(player);
			}
		}
		if (player.GetLives() == 0) { gameOver = true; }
	}
}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255, 100);
	doodle::draw_text("Heart: " + std::to_string(player.GetLives()), 30, Engine::GetWindow().GetSize().y - 150);
	doodle::push_settings();
	doodle::set_outline_width(7);
	doodle::set_outline_color(210, 253, 255);
	/*doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.75, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.75);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.5, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.5);
	doodle::draw_line(lineX, Engine::GetWindow().GetSize().y * 0.25, Engine::GetWindow().GetSize().x - lineX, Engine::GetWindow().GetSize().y * 0.25);*/
	//doodle::draw_line(-500, Engine::GetWindow().GetSize().y * 0.75, 500, Engine::GetWindow().GetSize().y * 0.75);
	doodle::apply_translate(Engine::GetWindow().GetSize().x * 0.5, Engine::GetWindow().GetSize().y * 0.5);
	doodle::apply_scale(1+sin(doodle::ElapsedTime*10)/400);
	doodle::draw_line(-500, Engine::GetWindow().GetSize().y * 0.25, 500, Engine::GetWindow().GetSize().y * 0.25);
	doodle::draw_line(-500, 0, 500, 0);
	doodle::draw_line(-500, -Engine::GetWindow().GetSize().y * 0.25, 500, -Engine::GetWindow().GetSize().y * 0.25);
	//doodle::draw_line(-500, Engine::GetWindow().GetSize().y * 0.25, 500, Engine::GetWindow().GetSize().y * 0.25); */
		doodle::pop_settings();

	if (gameOver)
	{
		doodle::draw_text("Game Over!", Engine::GetWindow().GetSize().x / 2 - 300, Engine::GetWindow().GetSize().y / 2);
	}
	else {
		for (Bug& b : bugs)
		{
			if (b.getStartTime() <= overlapseTime)
			{
				b.Draw();
			}
		}
		player.Draw();

		if (isAllDead())
		{
			switch (player.GetLives())
			{
			case 3:
				doodle::draw_text("perfect clear!", 40, Engine::GetWindow().GetSize().y / 2);
				break;
			case 2:
			case 1:
				doodle::draw_text("clear!", 40, Engine::GetWindow().GetSize().y / 2);
				break;
			case 0:
				doodle::draw_text("Fail", 40, Engine::GetWindow().GetSize().y / 2);

			}
		}
	}
}

bool Stage3::isAllDead()
{
	for (Bug& b : bugs)
	{
		if (b.getAlive()) { return false; }
	}
	return true;
}
