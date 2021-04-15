/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hacker_Stage2.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/13/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Sprite.h"
#include "DataBox.h"

class Hacker_Stage2 : public Retry::Object
{
private:
	math::vec2 initPos;
	
	constexpr static double appearTime = 10;
	double timer;

	bool isAppeard;

	math::vec2 boxPosition;

	// Retry::Sprite sprite;
public:
	bool hasDataBox;
	bool targettingBox;

	
	Hacker_Stage2(math::vec2 pos);
	void Load() override;
	void Update() override;
	void Draw() const override;

	void SetBoxPosition(math::vec2 boxPos) { boxPosition = boxPos; }

	bool IsAppeard() const { return isAppeard; }
};