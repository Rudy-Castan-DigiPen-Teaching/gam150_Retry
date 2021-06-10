/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: DataBoard.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/05/2021
-----------------------------------------------------------------*/
#include "DataBoard.h"
#include <doodle/random.hpp>

#include "../Engine/Engine.h"

DataBoard::DataBoard(double y, DataBox::DataType datatype) : Object({ 0, y }, 300, 25), dataType(datatype), reachedGoal(false), currDataNum(0) 
{
	hotspot = math::ivec2{ width / 2, 0 };
	position.x = static_cast<double>(datatype) * width + 540;
	goalDataNum = doodle::random(2, 5);

	switch (dataType)
	{
	case DataBox::DataType::RED:
		sprite.Load("assets/data_board_red.png", hotspot);
		break;
	case DataBox::DataType::GREEN:
		sprite.Load("assets/data_board_green.png", hotspot);
		break;
	case DataBox::DataType::BLUE:
		sprite.Load("assets/data_board_blue.png", hotspot);
		break;
	}
	width = sprite.GetTextureSize().x;
	height = sprite.GetTextureSize().y;
}

void DataBoard::Load() 
{
	goalDataNum = doodle::random(2, 5);
	currDataNum = 0;
}

void DataBoard::Update()
{
	if (currDataNum >= goalDataNum) 
	{
		currDataNum = 0;
		goalDataNum = doodle::random(2, 5);
	}
	if (currDataNum < 0)
	{
		currDataNum = 0;
	}
}

void DataBoard::Draw()
{
	doodle::push_settings();
	switch (dataType) {
	case DataBox::DataType::RED:
		doodle::set_fill_color(255, 0, 0, 255);
		break;
	case DataBox::DataType::GREEN:
		doodle::set_fill_color(0, 255, 0, 255);
		break;
	case DataBox::DataType::BLUE:
		doodle::set_fill_color(0, 0, 255, 255);
		break;
	}
	sprite.Draw(position);
	doodle::set_font_size(40);
	doodle::draw_text(std::to_string(currDataNum) + "/" + std::to_string(goalDataNum), position.x - 50, Engine::GetWindow().GetSize().y * 0.6);
	doodle::pop_settings();
}