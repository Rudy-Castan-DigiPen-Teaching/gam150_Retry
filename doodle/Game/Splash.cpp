#include "Splash.h"
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"

Splash::Splash() : StageNext(Retry::InputKey::Keyboard::Enter){}

void Splash::Load()
{
	Logo.Load("assets/DigiPen_BLACK_1024px.png");
}

void Splash::Update()
{
	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::TestStage);
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
