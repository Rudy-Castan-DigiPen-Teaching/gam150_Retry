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
#include <vector>
#include "../Engine/Scene.h"    // Scene (Base class)
#include "Player.h"
#include "Bug.h"
#include "../Engine/Sound.h"

class Stage3 : public Retry::Scene
{
	sf::Music music;
public:
	static constexpr double lineX = 200;
private:
	Retry::InputKey StageNext;
	Retry::InputKey Reload;
	Player player;
	std::vector<Bug> bugs;
	double overlapseTime = 0;
	bool gameOver = false;

public:
	Stage3();
	void Load() override;
	void Update() override;
	void Unload() override;
	void Draw() override;
	std::string GetName() override { return "Stage3"; }

	bool isAllDead();
};