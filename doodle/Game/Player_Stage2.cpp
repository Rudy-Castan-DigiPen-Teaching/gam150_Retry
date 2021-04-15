#include "Player_Stage2.h"

#include "DataBoard.h"
#include "../Engine/Engine.h"

Player_Stage2::Player_Stage2(math::vec2 position, double width, double height)
	: Object(position, width, height), initPos(position),
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	hasDataBox(false), speed(7)
{
}

Player_Stage2::Player_Stage2(double x, double y, double width, double height)
	: Player_Stage2({ x,y }, width, height)
{
}

void Player_Stage2::Load()
{
	position = initPos;
	hasDataBox = false;
	speed = 7;
}

void Player_Stage2::Update() {
	if (moveRightKey.IsKeyDown() == true) { position.x += speed; }
	if (moveLeftKey.IsKeyDown() == true) { position.x -= speed; }
	if (Engine::GetMouseInput().IsMousePressed()) {}

}

void Player_Stage2::Draw() const
{
	doodle::draw_rectangle(position.x, position.y, width, height);
}