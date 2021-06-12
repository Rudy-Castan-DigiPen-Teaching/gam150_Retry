/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Story.cpp
Project: GAM150_Networker
Author: Team RETRY - Haeun Park, Yujin Park
Creation date: 04/26/2021
-----------------------------------------------------------------*/

#include "Story.h"
#include <doodle/drawing.hpp>
#include "../Engine/Engine.h"

Story::Story() : mainmenu(Retry::InputKey::Keyboard::Enter)
{
	cutscenes.resize(static_cast<size_t>(cutscene::count));
}

void Story::Load()
{
	dialogueManager.AddDialogue({
			Dialogue("Boring.....  ","Zero"),
			Dialogue("(A piece of paper has fallen in front of you.)"),
			Dialogue("What is that?","Zero"),
			Dialogue("Huh. Phone number...?","Zero"),
			Dialogue("Good. I was just boring now. Let's make a prank call!","Zero"),
			Dialogue("(Beep. Beep. Beep. Beep)"),
			Dialogue("H...ell........o...?","..."),
			Dialogue("..........................?....!","Zero"),
			Dialogue("W...where am I? I should go back to home!","Zero")
		});
	dialogueManager.Load();

	cutscenes[static_cast<int>(cutscene::boring)].Load("assets/story_boring.png");
	cutscenes[static_cast<int>(cutscene::surprise)].Load("assets/story_surprise.png");
	cutscenes[static_cast<int>(cutscene::number_fall)].Load("assets/story_surprise.png");
	cutscenes[static_cast<int>(cutscene::number_surprise)].Load("assets/story_number_surprise.png");
	cutscenes[static_cast<int>(cutscene::number)].Load("assets/story_number.png");
	cutscenes[static_cast<int>(cutscene::calling)].Load("assets/story_calling.png");
	cutscenes[static_cast<int>(cutscene::calling_hello)].Load("assets/story_calling_hello.png");
	cutscenes[static_cast<int>(cutscene::what)].Load("assets/story_what.png");
	cutscenes[static_cast<int>(cutscene::network)].Load("assets/story_network_surprise.png");

}

void Story::Update(double)
{
	currscene = &cutscenes[dialogueManager.GetDialogueIndex()];

	dialogueManager.Update();
	if (Engine::GetMouseInput().IsMouseReleased() && end)
	{
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::Village);
	}

	if (dialogueManager.IsDone())
	{
		end = true;
	}
}

void Story::Unload()
{
	currscene = nullptr;
}

void Story::Draw()
{
	doodle::clear_background(0);
	dialogueManager.Draw();

	currscene->Draw((Engine::GetWindow().GetSize() - currscene->getSize() + math::ivec2{0, dialogueManager.GetRect().topRight.y}) / 2 );
}
