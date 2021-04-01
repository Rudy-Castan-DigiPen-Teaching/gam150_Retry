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

Stage1_Object::Stage1_Object(math::ivec2 initpos, double w, double h) : Object(initpos, w, h) {}

void Stage1_Object::Update(int num)
{
	switch (num)
	{
	case 0 :
		position.y -= 5;
		break;
	case 1:
		position.y -= 3;
		break;
	case 2:
		position.y -= 4;
		break;
	case 3 :
		position.y -= 2;
		break;
	}
}

void Stage1_Object::Draw(int num) const
{

	switch (num)
	{
	case 0:
		doodle::push_settings();
		doodle::set_fill_color(100, 0, 0);
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 1:
		doodle::push_settings();
		doodle::set_fill_color(0, 100, 0);
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 2:
		doodle::push_settings();
		doodle::set_fill_color(0, 0, 100);
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	case 3:
		doodle::push_settings();
		doodle::set_fill_color(200, 100, 100);
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	}
}
