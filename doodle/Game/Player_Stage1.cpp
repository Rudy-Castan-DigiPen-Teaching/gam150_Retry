#include "Player_Stage1.h"
#include <doodle/input.hpp>


Player_Stage1::Player_Stage1(math::vec2 position, double width, double height)
: Object(position,width,height) {}

Player_Stage1::Player_Stage1(double x, double y, double width, double height)
: Player_Stage1({x,y},width,height)
{
}

void Player_Stage1::Load()
{
	sprite.Load("assets/zero_standing.png");
}

void Player_Stage1::Update([[maybe_unused]]Retry::GameScenes scene)
{
	UpdateStage1();
}

void Player_Stage1::Draw()
{
	sprite.Draw({position.x, position.y});
}

void Player_Stage1::UpdateStage1()
{
	const double easing = 10.0 * doodle::DeltaTime;
	position.x += easing * (doodle::get_mouse_x() - position.x);

	SetPosition({ position.x, 100 });
}