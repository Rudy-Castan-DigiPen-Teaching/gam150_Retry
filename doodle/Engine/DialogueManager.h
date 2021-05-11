/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: DialogueManager.h
Project: GAM150_Networker
Author: Haeun Park
Creation date: 05/05/2021
-----------------------------------------------------------------*/
#pragma once
#include <vector>
#include <initializer_list>
#include <string>
#include "Vec2.h"
#include <doodle/image.hpp>

struct Rect {
	math::ivec2 bottomLeft;
	math::ivec2 topRight;
	Rect(math::ivec2 bl, math::ivec2 tr) : bottomLeft(bl), topRight(tr) {}
};

class Dialogue
{
	std::string name = "";


public:
	std::string sentence = "";
	Dialogue(std::string sentence)
		: sentence(std::move(sentence)) {}
	Dialogue(std::string sentence, std::string name)
		: sentence(std::move(sentence)), name(std::move(name)) {}
	std::string* GetSentence() { return &sentence; }
	const std::string GetName() const { return name; }

};

class DialogueManager {
private:
	Rect dialogueBox = { {10,10},{1260,210} };
	std::vector<Dialogue> dialogues;
	std::string displayString = " ";

	int index = 0;
	int visible_chars = 0;
	double timer = 0;
	double speed = 0.07;
	int count = 0;
	double fontSize = 30;

public:
	DialogueManager() = default;
	DialogueManager(std::initializer_list<Dialogue> list);

	void AddDialogue(Dialogue&& str);
	void AddDialogue(std::initializer_list<Dialogue>&& list);
	bool IsDone();
	void Load();
	void Update();
	void Draw();
	int GetDialogueIndex();

	~DialogueManager();
};