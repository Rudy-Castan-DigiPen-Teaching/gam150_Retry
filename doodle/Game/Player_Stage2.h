/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Player_Stage2.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"
#include "../Engine/Sound.h"
#include "Hacker_Stage2.h"

class Player_Stage2 : public Retry::Object
{
private:
	class State
	{
	public:
		virtual void Enter(Player_Stage2* player) = 0;
		virtual void Update(Player_Stage2* player) = 0;
		virtual void TestForExit(Player_Stage2* player) = 0;
		virtual std::string GetName() = 0;
	};
	class State_Idle : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Idle"; }
	};
	class State_Attacking : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Attack"; }
	};
	class State_Pushing : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Push"; }
	};
	class State_Pulling : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Pull"; }
	};
	class State_Carrying_Idle : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Carry-Idle"; };
	};
	class State_Carrying_Push : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Carry-Push"; };
	};
	class State_Carrying_Pull : public State
	{
		virtual void Enter(Player_Stage2* player) override;
		virtual void Update(Player_Stage2* player) override;
		virtual void TestForExit(Player_Stage2* player) override;
		std::string GetName() override { return "Carry-Pull"; };
	};
	State_Idle stateIdle;
	State_Attacking stateAttacking;
	State_Pushing statePushing;
	State_Pulling statePulling;
	State_Carrying_Idle stateCarryingIdle;
	State_Carrying_Push stateCarryingPush;
	State_Carrying_Pull stateCarryingPull;

	State* currState;

	void ChangeState(State* newState);

	void UpdateXVelocity();

	Retry::InputKey moveRightKey;
	Retry::InputKey moveLeftKey;

	math::vec2 initPos;

	Retry::Sprite sprite;
	Retry::Sprite attackSprite;
	Retry::Sprite flippedAttackSprite;

	Retry::Sound sound;

	enum SoundIndex
	{
		Attack
	};
	
	math::vec2 velocity;
	double xAccelerate;
	double xMaxVelocity;
	constexpr static double xDrag = 1600;

	constexpr static double attackTimer = 0.1;
	double attackTime;

	bool speedUp;
	bool isFast;

	bool isFlipped;
	bool isHitting;

	Object attackBox;

	Hacker_Stage2* hacker;

public:
	Player_Stage2(math::vec2 pos, int width, int height, Hacker_Stage2* hacker);

	void Load() override;
	void Update() override;
	void Draw() override;

	void SetVelocity(math::vec2 newVel) { velocity = newVel; }
	
	void MultiplySpeed(double d)
	{
		xAccelerate *= d;
		xMaxVelocity *= d;
	}

	void SpeedUp() { speedUp = true; }
	
	bool hasDataBox;	// Stage 2
};