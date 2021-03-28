#include "Player.h"

Player::Player(math::vec2 position, double width, double height)
: Object(position,width,height),
moveRightKey(Retry::InputKey::Keyboard::D), moveLeftKey(Retry::InputKey::Keyboard::A),
moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S)
{
}
Player::Player(double x, double y, double width, double height)
: Player({x,y},width,height)
{
}

void Player::Update()
{
	if (moveRightKey.IsKeyDown() == true) { position.x += 5; }
	if (moveLeftKey.IsKeyDown() == true) { position.x -= 5; }
	if (moveUpKey.IsKeyDown() == true) { position.y += 5; }
	if (moveDownKey.IsKeyDown() == true) { position.y -= 5; }
}

void Player::Draw() const
{
	doodle::draw_rectangle(position.x, position.y, width, height);
}
