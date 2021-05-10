/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage1_Object.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 04/01/2021
-----------------------------------------------------------------*/
#include "Stage1_Object.h"
#include <doodle/random.hpp>
#include "../Engine/Engine.h"

Stage1_Object::Stage1_Object(math::ivec2 initpos, int number, int dropspeed) : Object(initpos), numbering(number), player(0, 0, 0), speed(dropspeed){}


void Stage1_Object::Load()
{	
	correct_data.Load("assets/correct_data.png");
	incorrect_data.Load("assets/incorrect_data.png");
}


void Stage1_Object::Update()
{
	position.y -= speed;
}

void Stage1_Object::Draw_data()
{
	switch (numbering)
	{
	case 0 :
	case 1 :
		correct_data.Draw({position.x - hotspot.x, position.y - hotspot.y});
		break;
	case 2:
	case 3:
		incorrect_data.Draw({ position.x - hotspot.x, position.y - hotspot.y });
		break;
	}
}

bool Stage1_Object::Yisdown()
{
	if (position.y < 0)
	{
		return true;
	}
	return false;
}

Stage1_Item::Stage1_Item(math::ivec2 initpos, int dropspeed) : Object(initpos), speed(dropspeed) {}

void Stage1_Item::Load() 
{
	scissor.Load("assets/scissor.png");
}

void Stage1_Item::Update()
{
	position.y -= (speed / 2);
}

void Stage1_Item::Draw_Item()
{
	scissor.Draw({ position.x - hotspot.x, position.y - hotspot.y });
}

bool Stage1_Item::Yisdown() 
{
	if (position.y < 0)
	{
		return true;
	}
	return false;
}