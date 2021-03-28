#include "Stage1.h"
#include <doodle/drawing.hpp>

Stage1::Stage1() : StageNext(Retry::InputKey::Keyboard::Enter){}

void Stage1::Load()
{
}

void Stage1::Draw()
{
	doodle::clear_background(100, 20, 100, 255);
}

void Stage1::Update()
{
	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true)
	{
	  Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage2);
	}
}

void Stage1::Unload()
{
}