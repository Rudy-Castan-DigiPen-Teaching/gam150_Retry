/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Player_Stage2.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"
#include "Hacker_Stage2.h"

class Player_Stage2 : public Retry::Object
{
private:
	Retry::InputKey moveRightKey;
	Retry::InputKey moveLeftKey;

	math::vec2 initPos;

	Retry::Sprite sprite;
	
	math::vec2 velocity;
	double xAccelerate;
	double xMaxVelocity;
	constexpr static double xDrag = 1600;

	bool speedUp;
	bool isFast;

	bool isFilpped;
	bool isHitting;

	Object attackBox;

	Hacker_Stage2* hacker;

public:
	Player_Stage2(math::vec2 pos, int width, int height, Hacker_Stage2* hacker);

	void Load() override;
	void Update() override;
	void Draw() override;

	void MultiplySpeed(double d)
	{
		xAccelerate *= d;
		xMaxVelocity *= d;
	}

	void SpeedUp() { speedUp = true; }
	
	bool hasDataBox;	// Stage 2
};