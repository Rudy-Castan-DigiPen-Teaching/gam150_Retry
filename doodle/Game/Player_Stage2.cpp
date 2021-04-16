#include "Player_Stage2.h"

#include "DataBoard.h"
#include "../Engine/Engine.h"

Player_Stage2::Player_Stage2(math::vec2 position, int width, int height)
	: Object(position, width, height), initPos(position),
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	hasDataBox(false), speed(7)
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
	speed = 7;
}

void Player_Stage2::Update() {
	if (moveRightKey.IsKeyDown() == true) { position.x += speed; }
	else if (moveLeftKey.IsKeyDown() == true) { position.x -= speed; }
}

void Player_Stage2::Draw()
{
	//doodle::draw_rectangle(position.x, position.y, width, height);
	sprite.Draw(position);
}