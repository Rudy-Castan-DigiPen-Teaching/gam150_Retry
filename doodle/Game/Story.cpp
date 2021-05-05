#include "Story.h"
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"

Story::Story() : Mainmenu(Retry::InputKey::Keyboard::Enter) {}

void Story::Load()
{
}

void Story::Update(double)
{
	if (Mainmenu.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}
}

void Story::Unload()
{
}

void Story::Draw()
{
	doodle::clear_background(133, 230, 255);
}
