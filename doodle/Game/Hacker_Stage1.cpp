/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hacker_Stage1.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 04/26/2021
-----------------------------------------------------------------*/
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
