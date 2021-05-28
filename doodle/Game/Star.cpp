/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Star.cpp
Project: GAM150_Networker
Author: Haeun Park
Creation date: 05/26/2021
-----------------------------------------------------------------*/
#include "Star.h"
#include <doodle/random.hpp>
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"


Star::Star() :
	x(doodle::random(-Engine::GetWindow().GetSize().x, Engine::GetWindow().GetSize().x)),
	y(doodle::random(-Engine::GetWindow().GetSize().y, Engine::GetWindow().GetSize().y)),
	z(doodle::random(Engine::GetWindow().GetSize().x))
{
}

void Star::Update(double dt)
{
	math::vec2 winsize = Engine::GetWindow().GetSize();
	z -= zSpeed * dt;
	if (z < 1)
	{
		z = winsize.x;
		x = doodle::random(-winsize.x, winsize.x);
		y = doodle::random(-winsize.y, winsize.y);
	}

	radius = map(z, 0, winsize.x, 12, 1);
}

void Star::Draw()
{
	math::vec2 winsize = Engine::GetWindow().GetSize();

	double xscreen = map(x / z, 0, 1, 0, winsize.x);
	double yscreen = map(y / z, 0, 1, 0, winsize.y);

	doodle::push_settings();
	doodle::apply_translate(winsize.x / 2, winsize.y * 0.7);
	doodle::set_fill_color(220,220,255);
	doodle::no_outline();
	doodle::draw_ellipse(xscreen, yscreen, radius);
	doodle::pop_settings();
}

double Star::map(double val, double v_low, double v_up, double new_low, double new_up)
{
	double result = (val - v_low) / (v_up - v_low) * (new_up - new_low) + new_low;
	return result;
}
