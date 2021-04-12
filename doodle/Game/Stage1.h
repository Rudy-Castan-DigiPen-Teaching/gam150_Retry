/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage1.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"
#include "Stage1_Object.h"
#include "Player_Stage1.h"

class Stage1 : public Retry::Scene
{
private:
	Retry::InputKey StageNext;
	Player_Stage1 player;
	Stage1_Object s1;

	int time, score, heart, file, dropspeed;

public:
	Stage1();
	void Load() override;
	void Update() override;
	void Unload() override;
	void Draw() override;

	bool Identify_v();

	std::string GetName() override { return "Stage1"; };
};

inline 	std::vector<int> file_input;