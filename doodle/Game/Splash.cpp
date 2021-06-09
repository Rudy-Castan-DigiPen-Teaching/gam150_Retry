/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Splash.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Splash.h"
#include <doodle/drawing.hpp>
#include <doodle/environment.hpp>

#include "../Engine/Engine.h"

Splash::Splash() {}

void Splash::Load()
{
	Logo.Load("assets/DigiPen_BLACK_1024px.png");
}

void Splash::Update(double dt)
{
	time += dt;

	if (time > 3.0)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::MainMenu);
	}
}

void Splash::Unload()
{
}

void Splash::Draw()
{
	doodle::clear_background(255);
	Logo.Draw(Engine::GetWindow().GetSize() / 2.0 - Logo.getSize() / 2.0);
}
