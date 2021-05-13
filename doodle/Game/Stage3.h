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
#include "../Engine/Sound.h"
#include "../Engine/Sprite.h"
#include "Player_Stage3.h"
#include "Bug.h"

class Stage3 : public Retry::Scene
{
	sf::Music music;
	Retry::Sprite hacker;
	Retry::Sprite heart;
	Retry::Sprite background;

public:
	static constexpr double lineX = 200;
private:
	Retry::InputKey StageNext;
	Retry::InputKey Reload;
	Retry::InputKey RolebackMenu;
	Retry::InputKey pausekey;
	Retry::InputKey CheatKey;
	Player_Stage3 player;
	std::vector<Bug*> bugs;
	double overlapseTime = 0;
	bool gameOver = false;
	bool screenShake = false;
	math::vec2 hackerPos;

	bool pause = true;
public:
	Stage3();
	void Load() override;
	void Update(double) override;
	void Unload() override;
	void Draw() override;
	std::string GetName() override { return "Stage3"; }

	void ScreenShake();

private:
	bool isAllDead();
	void Cheat();

};