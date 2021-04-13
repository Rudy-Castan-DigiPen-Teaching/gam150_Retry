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
#include "../Engine/SceneManager.h"
#include "../Engine/Sprite.h"

class Player_Stage1 : public Retry::Object
{
	Retry::Sprite sprite;

	public:
		Player_Stage1(math::vec2 position, double width, double height);
		Player_Stage1(double x, double y, double width, double height);
		void Load() override;
		void Update(Retry::GameScenes scene);
		void Draw();
		void UpdateStage1();
};

