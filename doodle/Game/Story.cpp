#include "Story.h"
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"

Story::Story() : mainmenu(Retry::InputKey::Keyboard::Enter) {}

void Story::Load()
{
	dialogueManager.AddDialogue({
			"Boring.....  ",
			"(A piece of paper has fallen in front of you.)",
			"What is that?",
			"(You pick up that paper.)",
			"Huh. Phone number...?",
			"Good. I was just boring now. Let's make a prank call!",
			"(Beep. Beep. Beep. Beep)",
			"(ring....ring....ring....)",
			"H...ell........o...?",
			"..........................?....!",
			"Where am I? I should go back to home!"
		});
	dialogueManager.Load();
}

void Story::Update()
{
	dialogueManager.Update();
	if (Engine::GetMouseInput().IsMouseReleased() && end)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::MainMenu);
	}

	if (dialogueManager.IsDone())
	{
		end = true;
	}
}

void Story::Unload()
{
}

void Story::Draw()
{
	doodle::clear_background(133, 230, 255);
	dialogueManager.Draw();
}
