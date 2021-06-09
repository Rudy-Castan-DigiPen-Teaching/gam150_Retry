/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Player_Stage3.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Player_Stage3.h"
#include <functional>
#include <doodle/random.hpp>
#include "../Engine/Engine.h"
#include "Stage3.h"
#include "zero_stage3_Anims.h"

Player_Stage3::Player_Stage3(math::vec2 position)
	: Object(position), startPosition{ position },
	moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S),
	attackBox({ position.x + width, position.y }, static_cast<int>(width * 1.8), height, { width / 2, height / 2 }),
	currState(nullptr)
{
}

void Player_Stage3::Load()
{
	sprite.Load("assets/zero_security.spt");
	attackSprite.Load("assets/attack_security.png");
	width = sprite.GetFrameSize().x;
	height = sprite.GetFrameSize().y;
	hotspot = { width / 2, height / 2 };

	sound.LoadSound("assets/error_002.ogg");
	sound.LoadSound("assets/scratch_001.ogg");
	sound.SetVolume(looseHeart, 20);
	sound.SetVolume(attack, 10);

	position = startPosition;
	currLine = NetworkLine::Middle;
	lives = 3;
	isMoved = false;
	isHitting = false;

	currState = &stateIdle;
	currState->Enter(this);
	UpdatePosition();
	sprite.PlayAnimation(static_cast<int>(Security_Anim::Stand_Anim));
}

void Player_Stage3::Update()
{
	sprite.Update(doodle::DeltaTime);
	currState->Update(this);
	currState->TestForExit(this);
}

void Player_Stage3::Draw()
{
	if (Engine::GetMouseInput().IsMousePressed() && isHitting)
	{
		doodle::push_settings();
		doodle::set_fill_color(0, 255, 0);
		attackSprite.Draw(attackBox.GetPosition());
		doodle::pop_settings();
	}
	sprite.Draw(position);
}

void Player_Stage3::LooseHeart()
{
	const int shakeAmount = 20;
	doodle::apply_translate(
		doodle::random(-shakeAmount, shakeAmount),
		doodle::random(-shakeAmount, shakeAmount));
	sound.PlaySound(looseHeart);
	if (lives > 0)
	{
		lives -= 1;
	}
}

void Player_Stage3::UpdatePosition()
{
	switch (currLine)
	{
	case NetworkLine::Top:
		position = { Stage3::lineX - width / 2, Engine::GetWindow().GetSize().y * 0.75 };
		break;
	case NetworkLine::Middle:
		position = { Stage3::lineX - width / 2, Engine::GetWindow().GetSize().y * 0.5 };
		break;
	case NetworkLine::Bottom:
		position = { Stage3::lineX - width / 2, Engine::GetWindow().GetSize().y * 0.25 };
		break;
	}
}

void Player_Stage3::ChangeState(State* newState)
{
	Engine::GetLogger().LogDebug("Player Leaving State: " + currState->GetName() + " Entering State: " + newState->GetName());
	currState = newState;
	currState->Enter(this);
}

void Player_Stage3::State_Idle::Enter(Player_Stage3* player)
{
	player->sprite.PlayAnimation(static_cast<int>(Security_Anim::Stand_Anim));
}

void Player_Stage3::State_Idle::Update(Player_Stage3*)
{
}

void Player_Stage3::State_Idle::TestForExit(Player_Stage3* player)
{
	if (player->moveUpKey.IsKeyDown() && player->currLine < NetworkLine::Top)
	{
		player->ChangeState(&player->stateMoving);
	}
	else if (player->moveDownKey.IsKeyDown() && player->currLine > NetworkLine::Bottom)
	{
		player->ChangeState(&player->stateMoving);
	}
	else if (Engine::GetMouseInput().IsMousePressed())
	{
		player->ChangeState(&player->stateAttacking);
	}
}


void Player_Stage3::State_Moving::Enter(Player_Stage3*)
{

}

void Player_Stage3::State_Moving::Update(Player_Stage3* player)
{
	if (player->isMoved == false)
	{
		if (player->moveUpKey.IsKeyDown())
		{
			player->currLine = static_cast<NetworkLine>(static_cast<int>(player->currLine) + 1);
			player->isMoved = true;
		}
		else if (player->moveDownKey.IsKeyDown())
		{
			player->currLine = static_cast<NetworkLine>(static_cast<int>(player->currLine) - 1);
			player->isMoved = true;
		}
	}
	player->UpdatePosition();
}

void Player_Stage3::State_Moving::TestForExit(Player_Stage3* player)
{
	if (player->moveUpKey.IsKeyReleased() || player->moveDownKey.IsKeyReleased())
	{
		player->isMoved = false;
		player->ChangeState(&player->stateIdle);
	}
	else if (Engine::GetMouseInput().IsMousePressed())
	{
		player->isMoved = false;
		player->ChangeState(&player->stateAttacking);
	}
}


void Player_Stage3::State_Attacking::Enter(Player_Stage3* player)
{
	player->sprite.PlayAnimation(static_cast<int>(Security_Anim::Attack_Anim));
}

void Player_Stage3::State_Attacking::Update(Player_Stage3* player)
{
	if (player->isHitting == false)
	{
		player->sound.PlaySound(attack);
		player->isHitting = true;
		player->attackBox.SetPosition({ player->position.x + player->width, player->position.y });
	}
	else { player->attackBox.SetPosition({ -100 }); }

}

void Player_Stage3::State_Attacking::TestForExit(Player_Stage3* player)
{
	if (player->moveUpKey.IsKeyDown() && player->currLine < NetworkLine::Top)
	{
		player->isHitting = false;
		player->ChangeState(&player->stateMoving);
	}
	else if (player->moveDownKey.IsKeyDown() && player->currLine > NetworkLine::Bottom)
	{
		player->isHitting = false;
		player->ChangeState(&player->stateMoving);
	}
	else if (Engine::GetMouseInput().IsMouseReleased())
	{
		player->isHitting = false;
		player->ChangeState(&player->stateIdle);
	}
}
