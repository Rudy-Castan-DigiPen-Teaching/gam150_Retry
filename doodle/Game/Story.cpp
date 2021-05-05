#include "Story.h"
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"

Story::Story() : Mainmenu(Retry::InputKey::Keyboard::Enter) {}

void Story::Load()
{
}

void Story::Update()
{
	if (Mainmenu.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::MainMenu);
	}
}

void Story::Unload()
{
}

void Story::Draw()
{
	doodle::clear_background(133, 230, 255);
}
