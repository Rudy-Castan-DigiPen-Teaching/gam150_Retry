/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage1_Object.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 04/01/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"
#include <vector>
#include "Player_Stage1.h"

class Stage1_Object : public Retry::Object
{
	public:
		Stage1_Object(math::ivec2 initpos, double w, double h, int number, int dropspeed);
		~Stage1_Object() {}

		void Update() override;
		void Draw() const override;
		void revector(int sp);
		int GetNumbering() { return numbering; }
		void SetSpeed(int plus) { speed = plus; }
		bool Yisdown();
private:
	int numbering, speed;
	Player_Stage1 player;
};

inline std::vector<Stage1_Object> num{};