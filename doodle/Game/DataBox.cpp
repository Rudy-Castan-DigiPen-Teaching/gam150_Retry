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
#include "../Engine/Engine.h"

DataBox::DataBox(DataType dataType) : Object({ 100, static_cast<double>(Engine::GetWindow().GetSize().y) }, 130, 100), velocity({0, 0}),
dataType(dataType), isStacked(true), isOnBoard(false), isTransfered(false), isTargetted(false), isStolen(false)
{
	hotspot = { width / 2, 0 };
	switch(dataType)
	{
	case DataType::RED:
		sprite.Load("assets/data_box_red.png", hotspot);
		break;
	case DataType::GREEN:
		sprite.Load("assets/data_box_green.png", hotspot);
		break;
	case DataType::BLUE:
		sprite.Load("assets/data_box_blue.png", hotspot);
		break;
	}
	width = sprite.GetTextureSize().x;
	height = sprite.GetTextureSize().y;
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
	if (isStacked == true && position.y > Stage2::floor)
	{
		velocity.y -= gravity * doodle::DeltaTime;
		position += velocity * doodle::DeltaTime;
	}
	if (isStacked == true && position.y <= Stage2::floor)
	{
		position.y = Stage2::floor;
	}
}

void DataBox::Draw()
{
	doodle::push_settings();
	sprite.Draw(position);
	doodle::pop_settings();
}