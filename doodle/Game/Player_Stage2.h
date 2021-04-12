/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Player.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"
<<<<<<< HEAD:doodle/Game/Player_Stage1.h
#include <doodle/doodle.hpp>

class Player_Stage1 : public Retry::Object
{
	public:
		Player_Stage1(math::vec2 position, double width, double height);
		Player_Stage1(double x, double y, double width, double height);
		void Update(Retry::GameScenes scene);
		void Draw() const override;
		void UpdateStage1();
=======

class Player_Stage2 : public Retry::Object
{
private:
	Retry::InputKey moveRightKey;
	Retry::InputKey moveLeftKey;

public:
	Player_Stage2(math::vec2 position, double width, double height);
	Player_Stage2(double x, double y, double width, double height);

	void Load() override;
	void Update() override;
	void Draw() const override;

	bool hasDataBox;	// Stage 2
>>>>>>> Stage2:doodle/Game/Player_Stage2.h
};

