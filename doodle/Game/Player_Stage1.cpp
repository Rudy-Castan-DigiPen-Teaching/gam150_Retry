#include "Player_Stage1.h"
#include <doodle/input.hpp>
#include <doodle/environment.hpp>
#include "zero_stage1_Anims.h"

Player_Stage1::Player_Stage1(math::vec2 position, int width, int height)
: Object(position,width,height) {}

Player_Stage1::Player_Stage1(double x, double y, int width, int height)
: Player_Stage1({x,y},width,height)
{
}

void Player_Stage1::Load()
{
	sprite.Load("assets/zero_stage1.spt");
	sprite.PlayAnimation(static_cast<int>(DataCollect_Anim::Walk_Anim));
}

void Player_Stage1::Update([[maybe_unused]]Retry::GameScenes scene)
{
	UpdateStage1();
	sprite.Update(doodle::DeltaTime);
}

void Player_Stage1::Draw()
{
	sprite.Draw({position.x, position.y});
}

void Player_Stage1::UpdateStage1()
{
	const double easing = 3.0 * doodle::DeltaTime;
	position.x += easing * (doodle::get_mouse_x() - position.x);

	SetPosition({ position.x, 95 });
}