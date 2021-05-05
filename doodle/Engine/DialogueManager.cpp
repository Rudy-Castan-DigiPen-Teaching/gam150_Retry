/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: DialogueManager.cpp
Project: GAM150_Networker
Author: Haeun Park
Creation date: 05/05/2021
-----------------------------------------------------------------*/
#include "DialogueManager.h"
#include <doodle/doodle.hpp>
#include <vector>
#include <initializer_list>
#include "Engine.h"
#include "Vec2.h"
using namespace doodle;


	DialogueManager::DialogueManager(std::initializer_list<std::string> list) :dialogues(list) {}

	void DialogueManager::AddDialogue(std::string&& str)
	{
		dialogues.push_back(std::move(str));
	}

	void DialogueManager::AddDialogue(std::initializer_list<std::string>&& list)
	{
		for (auto str : list)
		{
			dialogues.push_back(std::move(str));
		}
	}

	bool DialogueManager::IsDone()
	{
		return (visible_chars == static_cast<int>(dialogues[index].size()) && count == static_cast<int>(dialogues.size()) - 1);
	}

	void DialogueManager::Load()
	{
		index = 0;
	}

	void DialogueManager::Update()
	{
		if (!IsDone())
		{
			timer += doodle::DeltaTime;
			if (Engine::GetMouseInput().IsMouseReleased())
			{
				if (visible_chars < static_cast<int>(dialogues[index].size()))
				{
					visible_chars = static_cast<int>(dialogues[index].size());
				}
				else if (visible_chars == static_cast<int>(dialogues[index].size()) && count < static_cast<int>(dialogues.size()) - 1)
				{
					index++;
					visible_chars = 0;
					count++;
				}
			}

			if (timer > speed)
			{
				if (visible_chars < static_cast<int>(dialogues[index].size()))
				{
					visible_chars++;
				}
				timer = 0;
			}

			std::string temp = "";
			for (int i = 0; i < visible_chars; i++)
			{
				temp += dialogues[index][i];
			}
			displayString = temp;
		}

	}
	void DialogueManager::Draw()
	{
		push_settings();
		set_fill_color(0, 190);
		doodle::draw_rectangle(
			dialogueBox.bottomLeft.x, dialogueBox.bottomLeft.y,
			dialogueBox.topRight.x, dialogueBox.topRight.y);
		pop_settings();

		push_settings();
		set_font_size(fontSize);
		doodle::draw_text(displayString, dialogueBox.bottomLeft.x + 10.0, dialogueBox.topRight.y - fontSize - 10.0);
		pop_settings();
	}

int DialogueManager::GetDialogueIndex()
{
	return index;
}

DialogueManager::~DialogueManager()
	{

	}
