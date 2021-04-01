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

class Player : public Retry::Object
{
private:
	Retry::InputKey moveRightKey;
	Retry::InputKey moveLeftKey;
	Retry::InputKey moveUpKey;
	Retry::InputKey moveDownKey;

public:
	Player(math::vec2 position, double width, double height);
	Player(double x, double y, double width, double height);
	void Update(Retry::GameScenes scene);
	void Draw() const override;

	void UpdateStage1();
	void UpdateStage2();
	void UpdateStage3();

};
