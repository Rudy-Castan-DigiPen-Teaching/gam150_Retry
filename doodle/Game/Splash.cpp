#include "Splash.h"
#include <doodle/drawing.hpp>
#include <doodle/environment.hpp>

#include "../Engine/Engine.h"

Splash::Splash() {}

void Splash::Load()
{
	Logo.Load("assets/DigiPen_BLACK_1024px.png");
}

void Splash::Update()
{
	timer += doodle::DeltaTime;
	if (timer > 3)
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
