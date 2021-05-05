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
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"
#include "Stage1_Object.h"
#include "Player_Stage1.h"
#include "../Engine/Sound.h"

class Stage1 : public Retry::Scene
{
private:
	Retry::InputKey StageStart;
	Retry::InputKey StageReload;
	Retry::InputKey StageNext;
	Retry::InputKey RolebackMenu;
	
	Player_Stage1 player;
	
	Retry::Sprite sprite_file;
	Retry::Sprite sprite_c_file;
	Retry::Sprite sprite_in_file;
	Retry::Sprite default_file;
	Retry::Sprite background;
	Retry::Sprite MousePointer;

	Retry::Sprite sprite_file1;
	Retry::Sprite sprite_file2;
	Retry::Sprite sprite_file3;
	Retry::Sprite sprite_heart;

	int time, score, heart, file, dropspeed, sprite_num;
	bool GameStart, GameOver, GameClear, IsPreviousFileExist;

	Retry::Sound sound;

	enum SoundIndex {
		InsertCorrectFIle, InsertIncorrectFIle, CorrectMakeFIle, IncorrectMakeFile
	};

public:
	Stage1();
	void Load() override;
	void Update(double) override;
	void Unload() override;
	void Draw() override;

	bool Identify_v();
	void Getnumber(int number);
	void File_Draw(int file_number);
	void Heart_Draw(int heart_num);
	void revector(int sp);
	
	std::string GetName() override { return "Stage1"; };
};

inline 	std::vector<int> file_input;
inline std::vector<Stage1_Object> num{};