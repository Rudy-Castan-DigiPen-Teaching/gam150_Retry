#include "Player_Stage3.h"

#include <functional>

#include "../Engine/Engine.h"
#include "Stage3.h"

Player_Stage3::Player_Stage3(math::vec2 position)
	: Object(position), startPosition{ position },
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S),
	attackBox({ position.x + width, position.y }, width * 1.8, height, { width / 2, height / 2 })
{

}


void Player_Stage3::Load()
{
	sprite.Load("assets/zero_standing.png");
	width = sprite.getTextureSize().x;
	height = sprite.getTextureSize().y;
	hotspot = { width / 2, height / 2 };
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

void Player_Stage3::Update()
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
		position = { Stage3::lineX - width/2, Engine::GetWindow().GetSize().y * 0.75 };
		break;
	case NetworkLine::Middle:
		position = { Stage3::lineX - width/2, Engine::GetWindow().GetSize().y * 0.5 };
		break;
	case NetworkLine::Bottom:
		position = { Stage3::lineX - width/2, Engine::GetWindow().GetSize().y * 0.25 };
		break;
	}
	if (Engine::GetMouseInput().IsMousePressed() && isHitting == false)
	{
		sound.PlaySound(attack);
		isHitting = true;
		attackBox.SetPosition({ position.x + width, position.y });
	}
	else if (Engine::GetMouseInput().IsMouseReleased())
	{
		isHitting = false;
	}
	else { attackBox.SetPosition({ -100 }); }

}

void Player_Stage3::Draw() 
{
	if (Engine::GetMouseInput().IsMousePressed() && isHitting)
	{
		doodle::push_settings();
		doodle::set_fill_color(0, 255, 0);
		attackBox.Draw();
		doodle::pop_settings();
	}
	sprite.Draw(position);
}

void Player_Stage3::LooseHeart()
{
	sound.PlaySound(looseHeart);
	if (lives > 0)
	{	
		lives -= 1;
	}
}
