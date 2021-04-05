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

DataBoard::DataBoard(double y, DataBox::DataType datatype) : Object({ 0, y }, 80, 25), dataType(datatype) 
{
	position.x = static_cast<double>(datatype) * 100 + 500;
	goalDataNum = doodle::random(2, 5);
}

void DataBoard::Load() 
{
	goalDataNum = doodle::random(2, 5);
}

void DataBoard::Update()
{
	if (currDataNum == goalDataNum) 
	{
		currDataNum = 0;
	}
}

void DataBoard::Draw() const
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
	doodle::draw_rectangle(position.x, position.y, width, height);
	doodle::pop_settings();
}