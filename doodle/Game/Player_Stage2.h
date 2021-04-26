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
#include "../Engine/SceneManager.h"

class Player_Stage2 : public Retry::Object
{
private:
	Retry::InputKey moveRightKey;
	Retry::InputKey moveLeftKey;

	double speed;

	math::vec2 initPos;

	Retry::Sprite sprite;

public:
	Player_Stage2(math::vec2 position, int width, int height);
	Player_Stage2(double x, double y, int width, int height);

	void Load() override;
	void Update() override;
	void Draw();

	void SetSpeed(double d) { speed = d; }
	
	bool hasDataBox;	// Stage 2
};