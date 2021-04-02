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

Stage1_Object::Stage1_Object(math::ivec2 initpos, double w, double h, int number) : Object(initpos, w, h), numbering(number) {}

void Stage1_Object::Update()
{
	position.y -= 5;

	if (position.y == 0)
	{
		num.clear();
		revector();
	}
}

void Stage1_Object::Draw() const
{
	switch (numbering)
	{
	case 0 :
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
		doodle::set_fill_color(100, 100, 100);
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		doodle::pop_settings();
		break;
	}
}

void Stage1_Object::revector()
{
	num.push_back(Stage1_Object({ 200, Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4)));
	num.push_back(Stage1_Object({ 450, Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4)));
	num.push_back(Stage1_Object({ 700, Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4)));
	num.push_back(Stage1_Object({ 950, Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4)));
	num.push_back(Stage1_Object({ 1200, Engine::GetWindow().GetSize().y }, 40, 40, doodle::random(0, 4)));
}