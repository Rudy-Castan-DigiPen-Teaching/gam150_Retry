#include "Stage2.h"
#include <doodle/drawing.hpp>

Stage2::Stage2() {}

void Stage2::Load() 
{
}

void Stage2::Update()
{
	
	if (doodle::KeyIsPressed)
	{
		Engine::GetLogger().LogEvent("Key Pressed");
		switch (doodle::Key)
		{
		case doodle::KeyboardButtons::_2:
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
			break;
		default:
			break;
		}
	}
}

void Stage2::Unload()
{
}

void Stage2::Draw()
{
	doodle::clear_background(0, 0, 0, 255);

}