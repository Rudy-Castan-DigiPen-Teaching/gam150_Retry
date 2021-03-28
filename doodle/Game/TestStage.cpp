#include "../Engine/Engine.h"
#include "TestStage.h"
#include <doodle/drawing.hpp>
#include <doodle/environment.hpp>

TestStage::TestStage() : StageNext(Retry::InputKey::Keyboard::Enter), test1({ 700, 700 }, 100), test2({ 0, 0 }, 100)
{
}

void TestStage::Load()
{
}

void TestStage::Draw()
{
	doodle::clear_background(100, 20, 100, 255);
	test2.Draw();
	test1.Draw();
}

void TestStage::Update()
{
	test1.Update();
	if (test1.CollideWith(test2) == true) {
		Engine::GetLogger().LogDebug("Collision!");
	}
	else {
		Engine::GetLogger().LogDebug("No Collision");
	}

	if (StageNext.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
}

void TestStage::Unload()
{
}