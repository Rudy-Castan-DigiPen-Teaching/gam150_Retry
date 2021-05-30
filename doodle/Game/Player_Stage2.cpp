#include "Player_Stage2.h"

#include "DataBoard.h"
#include "../Engine/Engine.h"

Player_Stage2::Player_Stage2(math::vec2 position, int width, int height, Hacker_Stage2* hacker)
	: Object(position, width, height), initPos(position), 
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	attackBox({position.x + width / 2, position.y}, 100, 100, {0, 0}),
	velocity(0, 0), xAccelerate(800), xMaxVelocity(600), hacker(hacker),
	speedUp(false), isFast(false), isFilpped(false), isHitting(false), hasDataBox(false)
{
}

void Player_Stage2::Load()
{
	hotspot = math::ivec2(48, 0);
	sprite.Load("assets/zero_datatransfer.png", hotspot);
	position = initPos;
	width = sprite.getTextureSize().x;
	height = sprite.getTextureSize().y;
	hasDataBox = false;
	velocity = { 0, 0 };
	xAccelerate = 800;
	xMaxVelocity = 600;
	speedUp = false;
	isFast = false;
	isFilpped = false;
	isHitting = false;

	attackBox.SetSize({ sprite.getTextureSize().x * 2, sprite.getTextureSize().y });
}

void Player_Stage2::Update() {
	if (hasDataBox == false && Engine::GetMouseInput().IsMousePressed() == true)
	{
		isHitting = true;
		if (isFilpped == true)
		{
			attackBox.SetPosition({ position.x - attackBox.GetSize().x - width / 2, position.y });
		}
		else
		{
			attackBox.SetPosition({ position.x + width / 2, position.y });
		}
	}
	else
	{
		isHitting = false;
	}
	if (isHitting == true)
	{
		attackBox.SetPosition({ -100, -100 });
		if (attackBox.CollideWith(*hacker))
		{
			hacker->hasDataBox = true;
		}
	}

	if (speedUp == true && isFast == false)
	{
		MultiplySpeed(1.5);
		isFast = true;
	}
	if (moveRightKey.IsKeyDown() == true)
	{
		isFilpped = false;
		velocity.x += xAccelerate * doodle::DeltaTime;
		if (velocity.x < 0)
		{
			velocity.x += xDrag * doodle::DeltaTime;
			velocity.x += xAccelerate * doodle::DeltaTime;
		}
		if (velocity.x > xMaxVelocity)
		{
			velocity.x = xMaxVelocity;
		}
	}
	else if (moveLeftKey.IsKeyDown() == true)
	{
		isFilpped = true;
		velocity.x -= xAccelerate * doodle::DeltaTime;
		if (velocity.x > 0)
		{
			velocity.x -= xDrag * doodle::DeltaTime;
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
			velocity.x += xDrag * doodle::DeltaTime;
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
	position += velocity * doodle::DeltaTime;
}

void Player_Stage2::Draw()
{
	sprite.Draw(position);
	if (isHitting == true)
	{
		attackBox.Draw();
	}
}