#include "DataBox.h"

DataBox::DataBox(DataKinds dataKind) : Object({0, 0}, 100, 50), dataKind(dataKind), isStacked(false), isOnBoard(false)
{
	hotspot = { width / 2, 0 };
}

void DataBox::Load() 
{
	isStacked = false;
	isOnBoard = false;
}

void DataBox::Update() 
{

	if (isStacked == false && isOnBoard == false) {
		// position.x = player.GetPosition,x + a;
		// position.y = a;
	}

	switch (dataKind) {
	case DataKinds::RED:
		break;
	case DataKinds::GREEN:
		break;
	case DataKinds::BLUE:
		break;
	}
}

void DataBox::Draw() const 
{
	doodle::push_settings();
	switch (dataKind) {
	case DataKinds::RED:
		break;
	case DataKinds::GREEN:
		break;
	case DataKinds::BLUE:
		break;
	}
	doodle::pop_settings();
}