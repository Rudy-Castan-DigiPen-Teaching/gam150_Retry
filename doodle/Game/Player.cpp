#include "Player.h"
#include "../Engine/Engine.h"

Player::Player(math::vec2 position, double width, double height)
	: Object(position, width, height),
	moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
	moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S),
	hasDataBox(false)
{
}
Player::Player(double x, double y, double width, double height)
	: Player({ x,y }, width, height)
{
}

void Player::Load() 
{
	hasDataBox = false;
}

void Player::Update(Retry::GameScenes scene)
{
	switch (scene) {
	case Retry::GameScenes::Stage1:
		break;
	case Retry::GameScenes::Stage2:
		UpdateStage2();
		break;
	case Retry::GameScenes::Stage3:
		break;
	}
}

void Player::Draw() const
{
	doodle::draw_rectangle(position.x, position.y, width, height);
}

void Player::UpdateStage2() {
	if (moveRightKey.IsKeyDown() == true) { position.x += 5; }
	if (moveLeftKey.IsKeyDown() == true) { position.x -= 5; }
	if (Engine::GetMouseInput().IsMousePressed()) {}

}