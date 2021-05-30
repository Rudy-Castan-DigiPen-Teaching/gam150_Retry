/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ending.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 05/06/2021
-----------------------------------------------------------------*/
#include "Ending.h"

#include <doodle/drawing.hpp>

#include "../Engine/Engine.h"

Ending::Ending() : exitkey(Retry::InputKey::Keyboard::Escape)
{
	prevScene = Retry::GameScenes::Village;
}

void Ending::Load()
{
	texture.Load("assets/Ending.png");
}

void Ending::Update(double)
{
	if (exitkey.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
}

void Ending::Unload()
{
}

void Ending::Draw()
{
	doodle::clear_background(100, 100, 255, 150);
	doodle::push_settings();
	
	texture.Draw((Engine::GetWindow().GetSize() / 2));
	doodle::pop_settings();

}
