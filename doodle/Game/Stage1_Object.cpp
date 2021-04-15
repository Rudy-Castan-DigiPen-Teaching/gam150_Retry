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

Stage1_Object::Stage1_Object(math::ivec2 initpos, int w, int h, int number, int dropspeed) : Object(initpos, w, h), numbering(number), player(0, 0, 0), speed(dropspeed){}


void Stage1_Object::Load()
{
	sprite_file1.Load("assets/file_1insert.png");
	sprite_file2.Load("assets/file_2insert.png");
	sprite_file3.Load("assets/file_3insert.png");
	heart.Load("assets/Sprite-0001.png");
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
	case 1:
		doodle::push_settings();
		doodle::set_fill_color(0, 100, 0);   //green
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 2:
	case 3:
		doodle::push_settings();
		doodle::set_fill_color(100, 0, 0);   //red
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	}
}


void Stage1_Object::revector(int sp)
{
	num.push_back(Stage1_Object({ doodle::random( 100, Engine::GetWindow().GetSize().x - 100), Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4), sp));
}

void Stage1_Object::File_Draw(int file_number)
{
	switch (file_number)
	{
	case 1:
		sprite_file1.Draw({ 50, 750 });
		break;
	case 2:
		sprite_file2.Draw({ 50, 750 });
		break;
	case 3:
		sprite_file3.Draw({ 50, 750 });
		break;
	}
}

void Stage1_Object::Heart_Draw(int heart_num)
{
	switch (heart_num)
	{
	case 1:
		heart.Draw({ 50, 600 });
		break;
	case 2:
		heart.Draw({ 50, 600 });
		heart.Draw({ 150, 600 });
		break;
	case 3:
		heart.Draw({ 50, 600 });
		heart.Draw({ 150, 600 });
		heart.Draw({ 250, 600 });
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