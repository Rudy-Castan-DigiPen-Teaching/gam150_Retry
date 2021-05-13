#include "GoodBug.h"
#include "../Engine/Engine.h"

void GoodBug::Load()
{
	sprite.Load("assets/Bug2.png");
}

void GoodBug::Update(Player_Stage3& player)
{
	if (isAlive == true)
	{
		position.x -= speed;

		if (position.x < 0 + width)
		{
			isAlive = false;
			Engine::GetLogger().LogDebug("Saved the good Bug!");
		}

		if (player.GetIsPlayerHitting() && CollideWith(player.GetAttackBox()))
		{
			player.LooseHeart();
			HitByPlayer();
			Engine::GetLogger().LogDebug("Hit the Good Bug");
		}
	}
}

void GoodBug::Draw()
{
	doodle::push_settings();
	doodle::set_fill_color(100);
	if (isAlive) {
		//doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
		sprite.Draw(position);
	}
	doodle::pop_settings();
}
