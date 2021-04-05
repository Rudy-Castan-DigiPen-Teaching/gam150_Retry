#include "Player.h"

#include <functional>

#include "../Engine/Engine.h"
#include "Stage3.h"

Player::Player(math::vec2 position, double width, double height)
	: Object(position, width, height),
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S),
attackBox({ position.x + width, position.y }, width, height,{ width / 2, height / 2 })
{
	hotspot = { width / 2, height / 2 };
}
Player::Player(double x, double y, double width, double height)
	: Player({ x,y }, width, height)
{
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
	//Engine::GetLogger().LogDebug("isMoved: " + std::to_string(isMoved));

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

	if (Engine::GetMouseInput().IsMousePressed())
	{
		isHitting = true;
		attackBox.SetPosition({ position.x + width, position.y });
	}
	else { isHitting = false; }
}

void Player::Draw() const
{
	doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);

	if (Engine::GetMouseInput().IsMousePressed())
	{
		attackBox.Draw();
	}
}
