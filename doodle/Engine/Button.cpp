/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Button.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 04/21/2021
-----------------------------------------------------------------*/
#include <doodle/doodle.hpp>
#include "Button.h"
#include "Engine.h"

Button::Button(const std::filesystem::path& filePath, math::vec2 pos) : pos_x{ pos.x }, pos_y{ pos.y }
{
	texture.Load(filePath);
	button_width = texture.getSize().x;
	button_height = texture.getSize().y;
}

Button::Button(std::string tex, math::vec2 pos, double width, double height) : Button(tex, pos.x, pos.y, width, height)
{
}

Button::Button(std::string tex, double x, double y, double width, double height) : text{ tex }, pos_x{ x }, pos_y{ y }, button_width{ width }, button_height{ height } {}
Button::Button(std::string tex, double x, double y, double width, double height, double fnt_size) : text{ tex }, pos_x{ x }, pos_y{ y }, button_width{ width }, button_height{ height } {setFontSize(fnt_size); }

bool Button::isMouseOnButton()
{
	if (doodle::get_mouse_x() < pos_x + button_width / 2 && doodle::get_mouse_x() > pos_x - button_width / 2 && doodle::get_mouse_y() < pos_y + button_height / 2 && doodle::get_mouse_y() > pos_y - button_height / 2)
		return true;
	else
		return false;
}

void Button::Update()
{
	if (isMouseOnButton() && Engine::GetMouseInput().IsMousePressed())
	{
		buttonPressed = true;
	}
	else {
		buttonPressed = false;
	}
}

void Button::Draw()
{
	doodle::push_settings();
	if (this->isMouseOnButton())
	{
		doodle::set_fill_color(180);
		doodle::set_tint_color(150, 150, 230);
	}
	else
		doodle::set_fill_color(255);
	doodle::set_rectangle_mode(doodle::RectMode::Center);
	doodle::set_font_size(fnt_size);
	doodle::draw_text(text, pos_x - text.size() / 2 * (fnt_size - 5), pos_y - fnt_size + 5);
	texture.Draw({ pos_x - button_width/2, pos_y - button_height/2});
	doodle::pop_settings();
}

void Button::setFontSize(double size)
{
	this->fnt_size = size;
}