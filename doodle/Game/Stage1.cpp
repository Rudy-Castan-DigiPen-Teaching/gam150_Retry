#include "Stage1.h"
#include <doodle/drawing.hpp>

Stage1::Stage1()
{
}

void Stage1::Load()
{
}

void Stage1::Draw()
{
}

void Stage1::Update()
{
	if (doodle::KeyIsPressed)
	{
		Engine::GetLogger().LogEvent("Key Pressed");
		switch (doodle::Key)
		{
		case doodle::KeyboardButtons::_1:
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
			break;
		default:
			break;
		}
	}
}

void Stage1::Unload()
{
}