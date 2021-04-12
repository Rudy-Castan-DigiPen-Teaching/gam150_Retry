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
#include "Player_Stage3.h"

class Bug : public Retry::Object
{
	Retry::Sound sound;
	enum SoundIndex { dead };
private:
	NetworkLine currLine;

	double startTime = 0;
	int speed = 10;

	bool isAlive = true;
	bool isHitThePlayer = false;
	bool crossedTheLine = false;

public:
	Bug(NetworkLine line) : Bug(line, 0) {}
	Bug(NetworkLine line, double sTime) : Bug(line, sTime, 10) {}
	Bug(NetworkLine line, double sTime, int speed);

	void Load();
	void Update(Player_Stage3& player);
	void Draw() const override;

	void setAlive(bool alive) { isAlive = alive; }

	double getStartTime() { return startTime; }
	bool getAlive() { return isAlive; }
	bool getHitThePlayer() { return isHitThePlayer; }
	bool getCrossedTheLine() { return crossedTheLine; }
	void HitByPlayer();
	void HitThePlayer();

};