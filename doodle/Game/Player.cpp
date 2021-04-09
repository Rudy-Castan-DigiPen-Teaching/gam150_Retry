#include "Player.h"

#include <functional>

#include "../Engine/Engine.h"
#include "Stage3.h"

Player::Player(math::vec2 position, double width, double height)
	: Object(position, width, height), startPosition{ position },
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S),
	attackBox({ position.x + width, position.y }, width * 1.8, height, { width / 2, height / 2 })
{
	hotspot = { width / 2, height / 2 };
}
Player::Player(double x, double y, double width, double height)
	: Player({ x,y }, width, height)
{
}

void Player::Load()
{
	sound.LoadSound("assets/error_002.ogg");
	sound.LoadSound("assets/scratch_001.ogg");
	sound.SetVolume(looseHeart, 30);
	sound.SetVolume(attack, 20);

	position = startPosition;
	currLine = NetworkLine::Middle;
	lives = 3;
	isMoved = false;
	isHitting = false;
}

void Player::Update(Retry::GameScenes scene)
{
	switch (scene)
	{
	case Retry::GameScenes::Stage1:
		//UpdateStage1();
		break;
	case Retry::GameScenes::Stage2:
		//UpdateStage2();
		break;
	case Retry::GameScenes::Stage3:
		UpdateStage3();
		break;
	}
}

void Player::UpdateStage3()
{
	if (isMoved == false)
	{
		if (moveUpKey.IsKeyDown() && currLine < NetworkLine::Top)
		{
			currLine = static_cast<NetworkLine>(static_cast<int>(currLine) + 1);
			isMoved = true;
		}
		else if (moveDownKey.IsKeyDown() && currLine > NetworkLine::Bottom)
		{
			currLine = static_cast<NetworkLine>(static_cast<int>(currLine) - 1);
			isMoved = true;
		}
	}
	if (moveUpKey.IsKeyReleased() || moveDownKey.IsKeyReleased())
	{
		isMoved = false;
	}

	switch (currLine)
	{
	case NetworkLine::Top:
		position = { Stage3::lineX - width, Engine::GetWindow().GetSize().y * 0.75 };
		break;
	case NetworkLine::Middle:
		position = { Stage3::lineX - width, Engine::GetWindow().GetSize().y * 0.5 };
		break;
	case NetworkLine::Bottom:
		position = { Stage3::lineX - width, Engine::GetWindow().GetSize().y * 0.25 };
		break;
	}
	if (Engine::GetMouseInput().IsMousePressed() && isHitting == false)
	{
		sound.PlaySound(1);
		isHitting = true;
		attackBox.SetPosition({ position.x + width, position.y });
	}
	else if (Engine::GetMouseInput().IsMouseReleased())
	{
		isHitting = false;
	}
	else { attackBox.SetPosition({ -100 }); }
}

void Player::Draw() const
{
	doodle::push_settings();
	doodle::set_fill_color(255, 85 * lives, 85 * lives);
	doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
	doodle::pop_settings();

	if (Engine::GetMouseInput().IsMousePressed() && isHitting)
	{
		doodle::push_settings();
		doodle::set_fill_color(0, 255, 0);
		attackBox.Draw();
		doodle::pop_settings();

	}
}

void Player::HitByBug()
{
	sound.PlaySound(looseHeart);
	if (lives > 0)
	{	
		lives -= 1;
	}
}
