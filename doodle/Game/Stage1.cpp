#include "Stage1.h"
#include <doodle/drawing.hpp>

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter){}

void Stage1::Load()
{
}

void Stage1::Draw()
{
}

void Stage1::Update()
{
	if (StageNext.IsKeyReleased() == true)
	{
			Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
}

void Stage1::Unload()
{
}