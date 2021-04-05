/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Bug.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 04/05/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"
#include "Player.h"

class Bug : public Retry::Object
{
private:
	NetworkLine currLine;

	int speed = 10;
	double startTime = 0;

	bool isAlive = true;
	bool isHitThePlayer = false;

public:
	Bug(NetworkLine line, double sTime);
	Bug(NetworkLine line) : Bug(line, 0) {}

	void Update();
	void Draw() const override;
	double getStartTime() { return startTime; }

	bool getAlive() { return isAlive; }
	bool getHitThePlayer() { return isHitThePlayer; }
	void HitByPlayer();
	void HitThePlayer();

};