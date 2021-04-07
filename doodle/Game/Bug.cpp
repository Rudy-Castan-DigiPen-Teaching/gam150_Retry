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

void Bug::Update(Player& p)
{
	if (isAlive == true)
	{
		position.x -= speed;
	}

	if (position.x < 0 + width )
	{
		p.HitByBug();
		isAlive = false;
		Engine::GetLogger().LogDebug("Can't kill the bug");

	}

}

void Bug::Draw() const
{
	doodle::push_settings();
	if (isAlive == false) { doodle::set_fill_color(0); }
	doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
	doodle::pop_settings();
}

void Bug::HitByPlayer()
{
	isAlive = false;
}

void Bug::HitThePlayer()
{
	isHitThePlayer = true;
}
