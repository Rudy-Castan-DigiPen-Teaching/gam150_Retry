/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GoodBug.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 05/13/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "Player_Stage3.h"
#include "Bug.h"

class GoodBug : public Bug
{
	Retry::Sprite sprite;
public:
	GoodBug(NetworkLine line) : Bug(line, 0) {}
	GoodBug(NetworkLine line, double sTime) : Bug(line, sTime, 10) {}
	GoodBug(NetworkLine line, double sTime, int speed) : Bug(line, sTime, speed) {}

	void Load()override;
	void Update(Player_Stage3& player)override;
	void Draw() override;

};