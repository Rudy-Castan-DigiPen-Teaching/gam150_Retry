/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage3.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Scene.h"    // Scene (Base class)
#include "Player.h"
#include "TestObject.h"

class Stage3 : public Retry::Scene
{
public:
	static constexpr double lineX = 200;
private:
	Retry::InputKey StageNext;
	Player player;
	TestObject bug;
public:
	Stage3();
	void Load() override;
	void Update() override;
	void Unload() override;
	void Draw() override;
	std::string GetName() override { return "Stage3"; }
};