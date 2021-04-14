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

#include <doodle/random.hpp>

#include "../Engine/Engine.h" // GetLogger

Stage3::Stage3() : StageNext(Retry::InputKey::Keyboard::Enter), Reload(Retry::InputKey::Keyboard::Escape),
player(Engine::GetWindow().GetSize() / 2.0) {}

void Stage3::Load()
{
	doodle::clear_background(255);
	hacker.Load("assets/hacker_standing.png");
	heart.Load("assets/Heart.png");
	music.openFromFile("assets/dambient_8-bit-loop.wav");
	gameOver = false;
	overlapseTime = 0;
	screenShake = false;
	hackerPos = math::vec2{ Engine::GetWindow().GetSize().x - static_cast<double>(hacker.getTextureSize().x), Engine::GetWindow().GetSize().y * 0.5 };
	player.Load();
	const double time_offset = 1;
	bugs.push_back(Bug(NetworkLine::Middle, time_offset));
	bugs.push_back(Bug(NetworkLine::Bottom, 5 + time_offset));
	bugs.push_back(Bug(NetworkLine::Top, 10 + time_offset));
	bugs.push_back(Bug(NetworkLine::Bottom, 20 + time_offset));
	bugs.push_back(Bug(NetworkLine::Middle, 35 + time_offset, 2));
	bugs.push_back(Bug(NetworkLine::Top, 68 + time_offset, 18));
	bugs.push_back(Bug(NetworkLine::Top, 70 + time_offset, 18));
	bugs.push_back(Bug(NetworkLine::Bottom, 75 + time_offset, 20));

	for (Bug& bug : bugs)
	{
		bug.Load();
	}

	music.setLoop(true);
	music.setVolume(8);
	music.play();
}

void Stage3::Unload()
{
	doodle::clear_background(100, 100, 255);
	bugs.clear();
	music.setLoop(false);
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

	//ScreenShake();

	if (!gameOver) {
		overlapseTime += 0.1;
		player.Update();

		for (Bug& bug : bugs)
		{
			if (bug.getStartTime() <= overlapseTime && bug.getAlive() == true)
			{
				bug.Update(player);
				hackerPos = { hackerPos.x ,bug.GetPosition().y };
			}
		}
		if (player.GetLives() == 0) { gameOver = true; }
	}
}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255, 150);
	for (int i = 1; i <= player.GetLives(); i++)
	{
		heart.Draw({ static_cast<double>(i * heart.getTextureSize().x) , static_cast<double>(Engine::GetWindow().GetSize().y - heart.getTextureSize().y) });
	}
	doodle::push_settings();
	doodle::set_outline_width(7);
	doodle::set_outline_color(210, 253, 255);

	doodle::apply_translate(Engine::GetWindow().GetSize().x * 0.5, Engine::GetWindow().GetSize().y * 0.5);
	doodle::apply_scale(1 + sin(doodle::ElapsedTime * 13) / 330);
	doodle::draw_line(-500, Engine::GetWindow().GetSize().y * 0.25, 500, Engine::GetWindow().GetSize().y * 0.25);
	doodle::draw_line(-500, 0, 500, 0);
	doodle::draw_line(-500, -Engine::GetWindow().GetSize().y * 0.25, 500, -Engine::GetWindow().GetSize().y * 0.25);
	doodle::pop_settings();

	hacker.Draw(hackerPos);
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

void Stage3::ScreenShake()
{
	const int shakeAmount = 30;
	if (Engine::GetMouseInput().IsMousePressed() && player.GetIsPlayerHitting() && !screenShake)
	{
		screenShake = true;
		doodle::apply_translate(
			doodle::random(-shakeAmount, shakeAmount),
			doodle::random(-shakeAmount, shakeAmount));
	}
	else if (Engine::GetMouseInput().IsMouseReleased())
	{
		screenShake = false;
	}
}
