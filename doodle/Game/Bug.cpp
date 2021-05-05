/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Bug.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 04/05/2021
-----------------------------------------------------------------*/
#include "Bug.h"
#include "../Engine/Engine.h"
#include "Stage3.h"

Bug::Bug(NetworkLine line, double sTime, int speed) : currLine(line), startTime(sTime), speed(speed)
{
	switch (line)
	{
	case NetworkLine::Top:
		position = { Engine::GetWindow().GetSize().x - Stage3::lineX, Engine::GetWindow().GetSize().y * 0.75 };
		break;
	case NetworkLine::Middle:
		position = { Engine::GetWindow().GetSize().x - Stage3::lineX, Engine::GetWindow().GetSize().y * 0.5 };
		break;
	case NetworkLine::Bottom:
		position = { Engine::GetWindow().GetSize().x - Stage3::lineX, Engine::GetWindow().GetSize().y * 0.25 };
		break;
	default:
		break;
	}
}

void Bug::Load()
{
	sound.LoadSound("assets/confirmation_004.ogg");
	sound.SetVolume(dead, 20);
}

void Bug::Update(Player_Stage3& player)
{
	if (isAlive == true)
	{
		position.x -= speed;

		if (position.x < 0 + width)
		{
			player.LooseHeart();
			isAlive = false;
			Engine::GetLogger().LogDebug("Can't kill the bug");
		}

		if (player.GetIsPlayerHitting() && CollideWith(player.GetAttackBox()))
		{
			sound.PlaySound(dead);
			HitByPlayer();
			Engine::GetLogger().LogDebug("Hit the Bug");
		}
	}
}

void Bug::Draw()
{
	doodle::push_settings();
	doodle::set_fill_color(100);
	if (isAlive) {
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
	}
	doodle::pop_settings();
}

void Bug::HitByPlayer()
{
	isAlive = false;
}

