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
