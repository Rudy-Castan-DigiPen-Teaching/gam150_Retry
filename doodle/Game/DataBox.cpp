/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: DataBox.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/01/2021
-----------------------------------------------------------------*/
#include "DataBox.h"
#include "Stage2.h"
#include "DataBoard.h"

DataBox::DataBox(DataType dataType) : Object({ 100, Stage2::floor }, 50, 50),
dataType(dataType), isStacked(true), isOnBoard(false), isTransfered(false), isTargetted(false), isStolen(false)
{
	hotspot = { width / 2, 0 };
}

void DataBox::Load() 
{
	isStacked = true;
	isOnBoard = false;
	isTransfered = false;
	isTargetted = false;
	isStolen = false;
}

void DataBox::Update() 
{
}

void DataBox::Draw() const 
{
	doodle::push_settings();
	switch (dataType) {
	case DataType::RED:
		doodle::set_fill_color(255, 0, 0, 255);
		break;
	case DataType::GREEN:
		doodle::set_fill_color(0, 255, 0, 255);
		break;
	case DataType::BLUE:
		doodle::set_fill_color(0, 0, 255, 255);
		break;
	}
	doodle::draw_rectangle(position.x, position.y, width, height);
	doodle::pop_settings();
}