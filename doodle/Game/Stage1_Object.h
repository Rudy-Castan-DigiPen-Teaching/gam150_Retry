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
#include <vector>
#include "Player_Stage1.h"
#include "../Engine/Sprite.h"

class Stage1_Object : public Retry::Object
{
	public:
		Stage1_Object(math::ivec2 initpos, double w, double h, int number, int dropspeed);
		~Stage1_Object() {}

		void Update() override;
		void Draw() const override;
		void Load() override;
		void revector(int sp);

		void File_Draw(int file_number);
		void Heart_Draw(int heart_num);
		int GetNumbering() { return numbering; }
		void SetSpeed(int plus) { speed = plus; }
		bool Yisdown();
private:
	int numbering, speed;
	Player_Stage1 player;
	Retry::Sprite sprite_file1;
	Retry::Sprite sprite_file2;
	Retry::Sprite sprite_file3;
	Retry::Sprite heart;
	
};

inline std::vector<Stage1_Object> num{};