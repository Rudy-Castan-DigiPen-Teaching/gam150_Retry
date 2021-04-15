/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hacker_Stage2.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/13/2021
-----------------------------------------------------------------*/
#include "Hacker_Stage2.h"
#include "../Engine/Engine.h"

Hacker_Stage2::Hacker_Stage2(math::vec2 pos) :
Object(pos, 100, 100), timer(0), isAppeard(false), hasDataBox(false), targettingBox(false),
boxPosition(Engine::GetWindow().GetSize()), initPos(pos)
{
	
}

void Hacker_Stage2::Load()
{
	position = initPos;
	timer = 0;
	isAppeard = false;
	hasDataBox = false;
	targettingBox = false;
	boxPosition = Engine::GetWindow().GetSize();
	hotspot = math::ivec2(48, 0);
	sprite.Load("assets/hacker_standing.png", hotspot);
	width = sprite.getTextureSize().x;
	height = sprite.getTextureSize().y;
}

void Hacker_Stage2::Update()
{
	if (timer >= appearTime)
	{
		isAppeard = true;
	}
	
	if (isAppeard == false)
	{
		timer += doodle::DeltaTime;
	}
	if (isAppeard == true) 
	{
		if (hasDataBox == false)
		{
			position.x -= 10;
		}
		else
		{
			position.x += 10;
			if (position.x > Engine::GetWindow().GetSize().x + width)
			{
				position.x = Engine::GetWindow().GetSize().x + width;
				boxPosition = Engine::GetWindow().GetSize();
				timer = 0;
				isAppeard = false;
				hasDataBox = false;
				targettingBox = false;
			}
		}
	}
	if (position.x < boxPosition.x)
	{
		position.x = boxPosition.x;
	}
}

void Hacker_Stage2::Draw()
{
	sprite.Draw(position);
}