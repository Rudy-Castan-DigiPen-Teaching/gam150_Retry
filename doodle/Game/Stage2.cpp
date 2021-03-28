#include "Stage2.h"
#include <doodle/drawing.hpp>

Stage2::Stage2() : StageNext(Retry::InputKey::Keyboard::Enter) {}

void Stage2::Load() 
{
}

void Stage2::Update()
{
	if (StageNext.IsKeyReleased() == true || Engine::GetMouseInput().IsMouseReleased() == true)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Stage3);
	}
}

void Stage2::Unload()
{
}

void Stage2::Draw()
{
	doodle::clear_background(0, 0, 0, 255);

}