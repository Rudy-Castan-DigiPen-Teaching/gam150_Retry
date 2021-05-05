#include "Story.h"
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"

Story::Story() : mainmenu(Retry::InputKey::Keyboard::Enter) {}

void Story::Load()
{
	dialogueManager.AddDialogue({
			Dialogue("Boring.....  ","Zero"),
			Dialogue("(A piece of paper has fallen in front of you.)"),
			Dialogue("What is that?","Zero"),
			Dialogue("(You pick up that paper.)"),
			Dialogue("Huh. Phone number...?","Zero"),
			Dialogue("Good. I was just boring now. Let's make a prank call!","Zero"),
			Dialogue("(Beep. Beep. Beep. Beep)"),
			Dialogue("(ring....ring....ring....)"),
			Dialogue("H...ell........o...?","..."),
			Dialogue("..........................?....!","Zero"),
			Dialogue("W...where am I? I should go back to home!","Zero")
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
