#include "Hacker_Stage1.h"
#include "../Engine/Engine.h"

Hacker_Stage1::Hacker_Stage1(math::vec2 initpos) : Object(initpos){}

void Hacker_Stage1::Load()
{
	position = initPos;
	hotspot = math::ivec2( 720,0 );
	sprite.Load("assets/hacker_hindrance.png", hotspot);

	width = sprite.getTextureSize().x;
	height = sprite.getTextureSize().y;
}

void Hacker_Stage1::Update()
{
	position.y -= 3;
}

void Hacker_Stage1::Draw()
{
	sprite.Draw(position);
}
