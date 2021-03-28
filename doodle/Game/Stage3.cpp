/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage3.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#include "Stage3.h"
#include <doodle/drawing.hpp>

Stage3::Stage3() : StageNext(Retry::InputKey::Keyboard::Escape){}

void Stage3::Load()
{
}

void Stage3::Update()
{
	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
}

void Stage3::Unload()
{
}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255);
}
