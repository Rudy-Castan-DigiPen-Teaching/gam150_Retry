#include "Player_Stage2.h"

#include "DataBoard.h"
#include "../Engine/Engine.h"

Player_Stage2::Player_Stage2(math::vec2 position, double width, double height)
	: Object(position, width, height),
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	hasDataBox(false)
{
}

Player_Stage2::Player_Stage2(double x, double y, double width, double height)
	: Player_Stage2({ x,y }, width, height)
{
}

void Player_Stage2::Load()
{
	hasDataBox = false;
}

void Player_Stage2::Update() {
	if (moveRightKey.IsKeyDown() == true) { position.x += 7; }
	if (moveLeftKey.IsKeyDown() == true) { position.x -= 7; }
	if (Engine::GetMouseInput().IsMousePressed()) {}

}

void Player_Stage2::Draw() const
{
	doodle::draw_rectangle(position.x, position.y, width, height);
}