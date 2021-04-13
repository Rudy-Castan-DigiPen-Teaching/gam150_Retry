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
#include <doodle/drawing.hpp>
#include <doodle/random.hpp>
#include "../Engine/Engine.h"

Stage1_Object::Stage1_Object(math::ivec2 initpos, double w, double h, int number, int dropspeed) : Object(initpos, w, h), numbering(number), player(0, 0, 0), speed(dropspeed){}


void Stage1_Object::Load()
{
	sprite.Load("assets/file.png");
	sprite.Load("assets/file_1insert.png");
	sprite.Load("assets/file_2insert.png");
	sprite.Load("assets/file_3insert.png");
	sprite.Load("assets/correct_file.png");
	sprite.Load("assets/incorrect_file.png");
}


void Stage1_Object::Update()
{
	position.y -= speed;
}

void Stage1_Object::Draw() const
{
	switch (numbering)
	{
	case 0 :
		doodle::push_settings();
		doodle::set_fill_color(100, 0, 0);   //red
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 1:
		doodle::push_settings();
		doodle::set_fill_color(0, 100, 0);   //green
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 2:
		doodle::push_settings();
		doodle::set_fill_color(0, 0, 100);   //blue
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 3:
		doodle::push_settings();
		doodle::set_fill_color(100, 100, 100);  //grey
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	}
}



void Stage1_Object::revector(int sp)
{
	num.push_back(Stage1_Object({ doodle::random( 100, Engine::GetWindow().GetSize().x - 100), Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4), sp));
}


bool Stage1_Object::Yisdown()
{
	if (position.y < 0)
	{
		return true;
	}
	return false;
}