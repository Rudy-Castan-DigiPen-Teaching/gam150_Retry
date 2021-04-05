#include "DataBox.h"
#include "Player.h"
#include "Stage2.h"

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

	switch (dataType) {
	case DataType::RED:
		break;
	case DataType::GREEN:
		break;
	case DataType::BLUE:
		break;
	}
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