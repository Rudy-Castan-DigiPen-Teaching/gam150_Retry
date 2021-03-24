#include "Splash.h"

#include <doodle/drawing.hpp>

Splash::Splash()
{
}

void Splash::Load()
{
	Logo.Load("assets/DigiPen_BLACK_1024px.png");
}

void Splash::Update()
{
	if (doodle::KeyIsPressed)
	{
		Engine::GetLogger().LogEvent("Key Pressed");
		switch (doodle::Key)
		{
		case doodle::KeyboardButtons::Enter:
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage1);
			break;
		default:
			break;
		}
	}
}

void Splash::Unload()
{
}

void Splash::Draw()
{
	doodle::clear_background(255);
	Logo.Draw(-Logo.getSize() / 2.0);
}
