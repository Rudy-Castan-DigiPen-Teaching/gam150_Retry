#include "Stage3.h"
#include <doodle/drawing.hpp>

Stage3::Stage3()
{
}

void Stage3::Load()
{
}

void Stage3::Update()
{
	if (doodle::KeyIsPressed)
	{
		Engine::GetLogger().LogEvent("Key Pressed");
		switch (doodle::Key)
		{
		case doodle::KeyboardButtons::_3:
			Engine::GetSceneManager().Shutdown();
			break;
		default:
			break;
		}
	}
}

void Stage3::Unload()
{
}

void Stage3::Draw()
{
	doodle::clear_background(100, 100, 255);
}
