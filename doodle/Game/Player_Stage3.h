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
#include "../Engine/Sound.h"

enum class NetworkLine
{
	Bottom, Middle, Top
};

class Player_Stage3 : public Retry::Object
{
	Retry::Sound sound;

	enum SoundIndex
	{
		looseHeart, attack
	};
private:
	math::vec2 startPosition;

	Retry::InputKey moveRightKey;
	Retry::InputKey moveLeftKey;
	Retry::InputKey moveUpKey;
	Retry::InputKey moveDownKey;

	NetworkLine currLine = NetworkLine::Middle;

	int lives = 3;
	bool isMoved = false;
	bool isHitting = false;
	Object attackBox;

public:
	Player_Stage3(math::vec2 position, double width, double height);
	Player_Stage3(double x, double y, double width, double height);

	void Load();
	void Update(Retry::GameScenes scene);
	void UpdateStage3();
	void Draw() const override;

	const int GetLives() const { return lives; }
	const Object& GetAttackBox() const { return attackBox; }
	const bool GetIsPlayerHitting() const { return  isHitting; }

	void HitByBug();

};
