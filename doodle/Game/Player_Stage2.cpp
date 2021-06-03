#include "Player_Stage2.h"

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
	sound.SetVolume(Attack, 20);
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
}

void Player_Stage2::Update()
{
	
	if (isHitting == true && attackBox.CollideWith(*hacker))
	{
		// add sound effect
		hacker->hasDataBox = true;
	}
	

	currState->Update(this);
	currState->TestForExit(this);
	
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

void Player_Stage2::State_Idle::Enter(Player_Stage2*)
{
	Engine::GetMouseInput().setMousePressed(false);
}

void Player_Stage2::State_Idle::Update(Player_Stage2*)
{
}

void Player_Stage2::State_Idle::TestForExit(Player_Stage2* player)
{
	if (player->moveLeftKey.IsKeyDown() == true || player->moveRightKey.IsKeyDown() == true)
	{
		player->ChangeState(&player->stateMoving);
	}
	if (player->hasDataBox == true)
	{
		player->ChangeState(&player->stateCarrying);
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
		else
		{
			player->ChangeState(&player->stateMoving);
		}
	}
}

void Player_Stage2::State_Moving::Enter(Player_Stage2* player)
{
	Engine::GetMouseInput().setMousePressed(false);
	if (player->moveLeftKey.IsKeyDown() == true)
	{
		player->isFlipped = true;
	}
	else if (player->moveRightKey.IsKeyDown() == true)
	{
		player->isFlipped = false;
	}
}

void Player_Stage2::State_Moving::Update(Player_Stage2* player)
{
	player->UpdateXVelocity();
}

void Player_Stage2::State_Moving::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == true)
	{
		player->ChangeState(&player->stateCarrying);
	}
	else if (Engine::GetMouseInput().IsMousePressed())
	{
		player->ChangeState(&player->stateAttacking);
	}
	else if (player->velocity.x == 0)
	{
		player->ChangeState(&player->stateIdle);
	}
}

void Player_Stage2::State_Carrying::Enter(Player_Stage2*)
{
	Engine::GetMouseInput().setMousePressed(false);
}

void Player_Stage2::State_Carrying::Update(Player_Stage2* player)
{
	player->UpdateXVelocity();
}

void Player_Stage2::State_Carrying::TestForExit(Player_Stage2* player)
{
	if (player->hasDataBox == false)
	{
		if (player->velocity.x == 0)
		{
			player->ChangeState(&player->stateIdle);
		}
		else
		{
			player->ChangeState(&player->stateMoving);
		}
	}
}

void Player_Stage2::ChangeState(State* newState)
{
	Engine::GetLogger().LogDebug("Leaving State: " + currState->GetName() + " Entering State: " + newState->GetName());
	currState = newState;
	currState->Enter(this);
}
