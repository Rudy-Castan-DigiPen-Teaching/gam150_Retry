/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage3.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#include "Stage3.h"
#include <doodle/drawing.hpp>
#include <doodle/random.hpp>
#include "../Engine/Engine.h" // GetLogger
#include "GoodBug.h"
Stage3::Stage3() : StageNext(Retry::InputKey::Keyboard::Enter), RolebackMenu(Retry::InputKey::Keyboard::Escape), Reload(Retry::InputKey::Keyboard::R), pausekey(Retry::InputKey::Keyboard::Space), CheatKey(Retry::InputKey::Keyboard::Q),
player(Engine::GetWindow().GetSize() / 2.0)
{
	bugs.clear();
}

void Stage3::Load()
{
	pause = true;

	doodle::clear_background(100, 100, 255);

	hacker.Load("assets/hacker_standing.png");
	heart.Load("assets/Heart.png");
	background.Load("assets/stage3_background.png");
	music.openFromFile("assets/dambient_8-bit-loop.wav");
	gameOver = false;
	overlapseTime = 0;
	screenShake = false;
	hackerPos = math::vec2{ Engine::GetWindow().GetSize().x - static_cast<double>(hacker.getTextureSize().x), Engine::GetWindow().GetSize().y * 0.5 };
	player.Load();
	const double time_offset = 1;
	bugs.push_back(new Bug(NetworkLine::Middle, time_offset));
	bugs.push_back(new GoodBug(NetworkLine::Bottom, 2 + time_offset));
	bugs.push_back(new Bug(NetworkLine::Top, 3 + time_offset));
	bugs.push_back(new Bug(NetworkLine::Bottom, 4 + time_offset));
	bugs.push_back(new Bug(NetworkLine::Middle, 4.3 + time_offset, 2));
	bugs.push_back(new GoodBug(NetworkLine::Top, 7 + time_offset, 18));
	bugs.push_back(new Bug(NetworkLine::Top, 7.2 + time_offset, 18));
	bugs.push_back(new Bug(NetworkLine::Bottom, 9 + time_offset, 20));
	bugs.push_back(new GoodBug(NetworkLine::Middle, 13 + time_offset));
	bugs.push_back(new Bug(NetworkLine::Top, 13.4 + time_offset, 15));
	bugs.push_back(new GoodBug(NetworkLine::Bottom, 14 + time_offset, 15));
	bugs.push_back(new Bug(NetworkLine::Bottom, 14.2 + time_offset, 15));

	double time = 15;
	for (int i = 0; i < 13; i++)
	{
		int speed = 0;
		switch (doodle::random(3))
		{
		case 0:
			speed = 5;
			break;
		case 1:
			speed = 15;
			break;
		case 2:
			speed = 17;
			break;
		}

		NetworkLine addLine = NetworkLine::Middle;
		switch (doodle::random(3))
		{
		case 0:
			addLine = NetworkLine::Top;
			break;
		case 1:
			addLine = NetworkLine::Middle;
			break;
		case 2:
			addLine = NetworkLine::Bottom;
			break;
		default:
			break;
		}

		switch (doodle::random(2))
		{
		case 0:
			bugs.push_back(new Bug(addLine, time + time_offset, speed));
			break;
		case 1:
			bugs.push_back(new GoodBug(addLine, time + time_offset, speed));
			break;
		default:
			break;
		}

		time += 0.8;
	}

	for (Bug* bug : bugs)
	{
		bug->Load();
	}

	music.setLoop(true);
	music.setVolume(0);
	music.play();
}

void Stage3::Unload()
{
	doodle::clear_background(100, 100, 255);
	for (Bug* bug : bugs)
	{
		delete bug;
	}
	bugs.clear();
	music.stop();
}

void Stage3::Update(double dt)
{
#ifdef _DEBUG
	if (CheatKey.IsKeyReleased() == true)
	{
		Cheat();
	}
#endif
	if (Reload.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().ReloadScene();
	}
	if (RolebackMenu.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}
	if (pausekey.IsKeyReleased() == true)
	{
		pause = !pause;
	}	
	
	if (isAllDead() && StageNext.IsKeyReleased())
	{
		Engine::GetSceneManager().SetStageClear(Retry::GameScenes::Stage3);
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}
	if (isAllDead())
	{
		Engine::GetSceneManager().SetStageClear(Retry::GameScenes::Stage3);
	}
	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}
	
	if (!gameOver) {
		player.Update();
		if (!pause)
		{
			overlapseTime += dt;

			for (Bug* bug : bugs)
			{
				if (bug->GetStartTime() <= overlapseTime && bug->GetAlive() == true)
				{
					bug->Update(player);
					hackerPos = { hackerPos.x ,bug->GetPosition().y };
				}
			}
		}
		if (player.GetLives() == 0) { gameOver = true; }
	}
	else
	{
		Engine::GetSceneManager().setGameOver(Retry::GameScenes::Stage3);
	}
}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255, 150);
	doodle::set_tint_color(230 + sin(doodle::ElapsedTime) * 25, 180 + cos(doodle::ElapsedTime) * 25, 255);
	background.Draw(Engine::GetWindow().GetSize() * 0.5);
	doodle::no_tint();
	for (int i = 1; i <= player.GetLives(); i++)
	{
		heart.Draw({ static_cast<double>(i * heart.getTextureSize().x) , static_cast<double>(Engine::GetWindow().GetSize().y - heart.getTextureSize().y) });
	}
	doodle::push_settings();
	doodle::set_font_size(30);
	doodle::draw_text("Left Bugs: " + std::to_string(GetNumberOfAliveBug()), 30, 30);
	doodle::pop_settings();

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

	for (Bug* b : bugs)
	{
		if (b->GetStartTime() <= overlapseTime)
		{
			b->Draw();
		}
	}
	player.Draw();

	if (pause)
	{
		doodle::draw_text("Pause\nPress Space Bar to Start", 370, Engine::GetWindow().GetSize().y * 0.75);
	}

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

bool Stage3::isAllDead()
{
	for (Bug* b : bugs)
	{
		if (b->GetAlive()) { return false; }
	}
	return true;
}

void Stage3::Cheat()
{
	for (Bug* bug : bugs)
	{
		bug->setAlive(false);
	}
}

int Stage3::GetNumberOfAliveBug()
{
	int result = 0;
	for (Bug* bug : bugs)
	{
		if (bug->GetAlive())
		{
			result++;
		}
	}
	return result;
}

