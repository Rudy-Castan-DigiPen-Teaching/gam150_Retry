#include "Player_Stage2.h"

#include "DataBoard.h"
#include "../Engine/Engine.h"

Player_Stage2::Player_Stage2(math::vec2 position, int width, int height)
	: Object(position, width, height), initPos(position),
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	hasDataBox(false), velocity(0, 0), xAccelerate(800), xMaxVelocity(600), speedUp(false), isFast(false)
{
}

Player_Stage2::Player_Stage2(double x, double y, int width, int height)
	: Player_Stage2({ x,y }, width, height)
{
}

void Player_Stage2::Load()
{
	hotspot = math::ivec2(48, 0);
	sprite.Load("assets/zero_standing.png", hotspot);
	position = initPos;
	width = sprite.getTextureSize().x;
	height = sprite.getTextureSize().y;
	hasDataBox = false;
	velocity = { 0, 0 };
	xAccelerate = 800;
	xMaxVelocity = 600;
	speedUp = false;
	isFast = false;
}

void Player_Stage2::Update() {
	if (speedUp == true && isFast == false)
	{
		MultiplySpeed(1.5);
		isFast = true;
	}
	if (moveRightKey.IsKeyDown() == true)
	{
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
}