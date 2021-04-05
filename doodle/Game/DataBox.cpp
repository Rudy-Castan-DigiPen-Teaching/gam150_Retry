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
#include "Player.h"
#include "Stage2.h"
#include "DataBoard.h"

DataBox::DataBox(DataType dataType, const Player& player) : Object({100, Stage2::floor}, 50, 50), dataType(dataType), isStacked(true), isOnBoard(false), player(player)
{
	hotspot = { width / 2, 0 };
}

void DataBox::Load() 
{
	isStacked = true;
	isOnBoard = false;
}

void DataBox::Update() 
{

	if (isStacked == false && isOnBoard == false) {
		position.x = player.GetPosition().x + width;
	}

	
	// position.y = databoard.height + height * (databoard.GetCurrDataNum() - 1)
	// 여기서 데이터박스를 어케 올려야되지?? ㅜㅜ 데이터박스도 레퍼런스로 가져와야될듯
	// 앓~~ 살려줘
	/*
	* 그러니가 데이터박스를 레퍼런스로 가져와서
	* 어.. 레퍼런스로 가져오는건 같은 데이터타입이어야겠지?
	* 그럼 또 스테이지에셔 for문 조지게 돌려야되잖아 ㅋㅋ 에휴...
	* Too many loops
	* if (databoard.GetDataType() == databox.GetDataType()) {
	*	databox.
	* }
	*/
	

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