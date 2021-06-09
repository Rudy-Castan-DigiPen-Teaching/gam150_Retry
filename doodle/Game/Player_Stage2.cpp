/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Player_Stage2.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#include "Player_Stage2.h"
#include "zero_datatransfer_Anims.h"
#include "DataBoard.h"
#include "../Engine/Engine.h"

Player_Stage2::Player_Stage2(math::vec2 pos, int width, int height, Hacker_Stage2* hacker)
	: Object(pos, width, height), initPos(pos), 
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	attackBox({0, 0}, 100, 100, {0, 0}),
	velocity(0, 0), xAccelerate(800), xMaxVelocity(600), hacker(hacker),
	speedUp(false), isFast(false), isFlipped(false), isHitting(false), hasDataBox(false), currState(nullptr), attackTime(0)
{
	
}

void Player_Stage2::Load()
{
	//hotspot = math::ivec2(48, 0);
	sprite.Load("assets/zero_datatransfer.spt");
	attackSprite.Load("assets/attack_security.png", attackBox.GetHotspot());
	flippedAttackSprite.Load("assets/attack_flipped.png", attackBox.GetHotspot());
	sound.LoadSound("assets/scratch_001.ogg");
	sound.SetVolume(Attack, Retry::SoundOption::sfxVolume * 0.2f);
	position = initPos;
	width = sprite.GetFrameSize().x;
	height = sprite.GetFrameSize().y;
	hasDataBox = false;
	velocity = { 0, 0 };
	xAccelerate = 800;
	xMaxVelocity = 600;
	attackTime = 0;
	speedUp = false;
	isFast = false;
	isFlipped = false;
	isHitting = false;

	attackBox.SetPosition(position);
	attackBox.SetSize({ attackSprite.GetTextureSize().x, attackSprite.GetTextureSize().y });

	currState = &stateIdle;
	currState->Enter(this);

	sprite.PlayAnimation(static_cast<int>(static_cast<int>(DataTransfer_Anim::Stand_Anim)));
}

void Player_Stage2::Update()
{
	
	if (isHitting == true && attackBox.CollideWith(*hacker))
	{
		hacker->hasDataBox = true;
	}

	currState->Update(this);
	currState->TestForExit(this);
	sprite.Update(doodle::DeltaTime);
	
	if (speedUp == true && isFast == false)
	{
		MultiplySpeed(1.5);
		isFast = true;
	}

	position += velocity * doodle::DeltaTime;
	attackBox.UpdatePosition(velocity * doodle::DeltaTime);
}

void Player_Stage2::Draw()
{
	sprite.Draw(position);
	if (isHitting == true)
	{
		if (isFlipped == true)
		{
			flippedAttackSprite.Draw(attackBox.GetPosition());
		}
		else
		{
			attackSprite.Draw(attackBox.GetPosition());
		}
	}
}

void Player_Stage2::UpdateXVelocity()
{
	if (moveRightKey.IsKeyDown() == true)
	{
		isFlipped = false;
		velocity.x += xAccelerate * doodle::DeltaTime;
		if (velocity.x < 0)
		{
			velocity.x += Player_Stage2::xDrag * doodle::DeltaTime;
			velocity.x += xAccelerate * doodle::DeltaTime;
		}
		if (velocity.x > xMaxVelocity)
		{
			velocity.x = xMaxVelocity;
		}
	}
	else if (moveLeftKey.IsKeyDown() == true)
	{
		isFlipped = true;
		velocity.x -= xAccelerate * doodle::DeltaTime;
		if (velocity.x > 0)
		{
			velocity.x -= Player_Stage2::xDrag * doodle::DeltaTime;
			velocity.x -= xAccelerate * doodle::DeltaTime;
		}
		if (velocity.x < -xMaxVelocity)
		{
			velocity.x = -xMaxVelocity;
		}
	}
	else
	{
		if (velocity.x < 0)
		{
			velocity.x += Player_Stage2::xDrag * doodle::DeltaTime;
			if (velocity.x > doodle::DeltaTime)
			{
				velocity.x = 0;
			}
		}
		if (velocity.x > 0)
		{
			velocity.x -= xDrag * doodle::DeltaTime;
			if (velocity.x < doodle::DeltaTime)
			{
				velocity.x = 0;
			}
		}
	}

}

void Player_Stage2::State_Idle::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Stand_Anim));
}

void Player_Stage2::State_Idle::Update(Player_Stage2*)
{
}

void Player_Stage2::State_Idle::TestForExit(Player_Stage2* player)
{
	if (player->moveRightKey.IsKeyDown() == true)
	{
		player->ChangeState(&player->statePushing);
	}
	else if (player->moveLeftKey.IsKeyDown() == true)
	{
		player->ChangeState(&player->statePulling);
	}
	else if (Engine::GetMouseInput().IsMousePressed() == true)
	{
		player->ChangeState(&player->stateAttacking);
	}
}

void Player_Stage2::State_Attacking::Enter(Player_Stage2* player)
{
	player->sound.PlaySound(player->Attack);
}

void Player_Stage2::State_Attacking::Update(Player_Stage2* player)
{
	player->attackTime += doodle::DeltaTime;
	if (player->attackTime >= Player_Stage2::attackTimer)
	{
		Engine::GetMouseInput().setMousePressed(false);
	}
	player->UpdateXVelocity();
	if (player->isHitting == false && player->hasDataBox == false && Engine::GetMouseInput().IsMousePressed() == true)
	{
		player->isHitting = true;
		if (player->isFlipped == true)
		{
			player->attackBox.SetPosition({ player->position.x - player->attackBox.GetSize().x - player->GetHotspot().x, player->position.y });
		}
		else
		{
			player->attackBox.SetPosition({ player->position.x + player->GetHotspot().x, player->position.y });
		}
	}
}

void Player_Stage2::State_Attacking::TestForExit(Player_Stage2* player)
{
	if (Engine::GetMouseInput().IsMousePressed() == false)
	{
		player->isHitting = false;
		player->attackTime = 0;
		if (player->velocity.x == 0)
		{
			player->ChangeState(&player->stateIdle);
		}
		if (player->velocity.x < 0)
		{
			player->ChangeState(&player->statePulling);
		}
		if (player->velocity.x > 0)
		{
			player->ChangeState(&player->statePushing);
		}
		//else
		//{
		//	player->ChangeState(&player->stateMoving);
		//}
	}
}

void Player_Stage2::State_Pushing::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	player->isFlipped = false;
	player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Push_Anim));
	// player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Push_Anim));
}

void Player_Stage2::State_Pushing::Update(Player_Stage2* player)
{
	player->UpdateXVelocity();
}

void Player_Stage2::State_Pushing::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == true)
	{
		player->ChangeState(&player->stateCarryingPush);
	}
	if (player->velocity.x < 0)
	{
		player->ChangeState(&player->statePulling);
	}
	else if (player->hasDataBox == false && Engine::GetMouseInput().IsMousePressed())
	{
		player->ChangeState(&player->stateAttacking);
	}
	else if (player->velocity.x == 0)
	{
		player->ChangeState(&player->stateIdle);
	}
}

void Player_Stage2::State_Pulling::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	player->isFlipped = true;
	player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Pull_Anim));
	// player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Push_Anim));
}

void Player_Stage2::State_Pulling::Update(Player_Stage2* player)
{
	player->UpdateXVelocity();
}

void Player_Stage2::State_Pulling::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == true)
	{
		player->ChangeState(&player->stateCarryingPull);
	}
	if (player->velocity.x > 0)
	{
		player->ChangeState(&player->statePushing);
	}
	else if (player->hasDataBox == false && Engine::GetMouseInput().IsMousePressed())
	{
	player->ChangeState(&player->stateAttacking);
	}
	else if (player->velocity.x == 0)
	{
	player->ChangeState(&player->stateIdle);
	}
}

void Player_Stage2::State_Carrying_Idle::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Stand_Anim));
}

void Player_Stage2::State_Carrying_Idle::Update(Player_Stage2*)
{
}

void Player_Stage2::State_Carrying_Idle::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == false)
	{
		player->ChangeState(&player->stateIdle);
	}
	if (player->moveRightKey.IsKeyDown() == true)
	{
		player->ChangeState(&player->stateCarryingPush);
	}
	else if (player->moveLeftKey.IsKeyDown() == true)
	{
		player->ChangeState(&player->stateCarryingPull);
	}
}

void Player_Stage2::State_Carrying_Push::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Push_Anim));
}

void Player_Stage2::State_Carrying_Push::Update(Player_Stage2* player)
{
	player->UpdateXVelocity();
}

void Player_Stage2::State_Carrying_Push::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == false)
	{
		if (player->velocity.x > 0)
		{
			player->ChangeState(&player->statePushing);
		}
		else if (player->velocity.x < 0)
		{
			player->ChangeState(&player->statePulling);
		}
		else
		{
			player->ChangeState(&player->stateIdle);
		}
	}
	if (player->velocity.x < 0)
	{
		player->ChangeState(&player->stateCarryingPull);
	}
	else if (player->velocity.x == 0)
	{
		player->ChangeState(&player->stateCarryingIdle);
	}
}

void Player_Stage2::State_Carrying_Pull::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	player->sprite.PlayAnimation(static_cast<int>(DataTransfer_Anim::Pull_Anim));
}

void Player_Stage2::State_Carrying_Pull::Update(Player_Stage2* player)
{
	player->UpdateXVelocity();
}

void Player_Stage2::State_Carrying_Pull::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == false)
	{
		if (player->velocity.x > 0)
		{
			player->ChangeState(&player->statePushing);
		}
		else if (player->velocity.x < 0)
		{
			player->ChangeState(&player->statePulling);
		}
		else
		{
			player->ChangeState(&player->stateIdle);
		}
	}
	if (player->velocity.x > 0)
	{
		player->ChangeState(&player->stateCarryingPush);
	}
	else if (player->velocity.x == 0)
	{
		player->ChangeState(&player->stateCarryingIdle);
	}
}

void Player_Stage2::ChangeState(State* newState)
{
	Engine::GetLogger().LogDebug("Leaving State: " + currState->GetName() + " Entering State: " + newState->GetName());
	currState = newState;
	currState->Enter(this);
}
