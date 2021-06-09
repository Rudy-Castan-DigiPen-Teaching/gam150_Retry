/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Player_Stage3.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"
#include "../Engine/Sound.h"
#include "../Engine/Sprite.h"

enum class NetworkLine
{
	Bottom, Middle, Top
};

class Player_Stage3 : public Retry::Object
{
	Retry::Sound sound;
	Retry::Sprite sprite;
	
	enum SoundIndex
	{
		looseHeart, attack
	};

private:
	math::vec2 startPosition;

	Retry::InputKey moveUpKey;
	Retry::InputKey moveDownKey;

	NetworkLine currLine = NetworkLine::Middle;

	int lives = 3;
	bool isMoved = false;
	bool isHitting = false;
	Object attackBox;
	Retry::Sprite attackSprite;

public:
	Player_Stage3(math::vec2 position);

	void Load() override;
	void Update() override;
	void Draw() override;

	const int GetLives() const { return lives; }
	const Object& GetAttackBox() const { return attackBox; }
	const bool GetIsPlayerHitting() const { return  isHitting; }

	void LooseHeart();

private:
	class State {
	public:
		virtual void Enter(Player_Stage3* player) = 0;
		virtual void Update(Player_Stage3* player) = 0;
		virtual void TestForExit(Player_Stage3* player) = 0;
		virtual std::string GetName() = 0;
	};
	class State_Idle : public State {
	public:
		virtual void Enter(Player_Stage3* player) override;
		virtual void Update(Player_Stage3* player) override;
		virtual void TestForExit(Player_Stage3* player) override;
		std::string GetName() override { return "Idle"; }
	};
	class State_Moving : public State {
	public:
		virtual void Enter(Player_Stage3* player) override;
		virtual void Update(Player_Stage3* player) override;
		virtual void TestForExit(Player_Stage3* player) override;
		std::string GetName() override { return "Moving"; }
	};
	class State_Attacking : public State {
	public:
		virtual void Enter(Player_Stage3* player) override;
		virtual void Update(Player_Stage3* player) override;
		virtual void TestForExit(Player_Stage3* player) override;
		std::string GetName() override { return "Attacking"; }
	};
	State_Idle stateIdle;
	State_Moving stateMoving;
	State_Attacking stateAttacking;

	void UpdatePosition();
	void ChangeState(State* newState);
	State* currState;
};
