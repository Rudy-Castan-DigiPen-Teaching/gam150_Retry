/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Village.h
Project: GAM150_Networker
Author: Yeongju Lee
Creation date: 05/06/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Scene.h"
#include "../Engine/Input.h"
#include "../Engine/Vec2.h"
#include "../Engine/Texture.h"
#include <vector>

#include "../Engine/Sprite.h"

class Village : public Retry::Scene
{
public:
	Village();
	void Load() override;;
	void Update(double) override;
	void Unload() override;
	void Draw() override;
	std::string GetName() override { return "Village"; }

private:
	Retry::Texture howToPlay_Security;

	class QuestButton
	{
	public:
		QuestButton(math::vec2 pos, Retry::GameScenes stage, bool isLocked);

		void UnlockButton() { isLocked = false; }
		bool IsLocked() { return isLocked; }
		
		bool IsMouseOn();
		bool IsButtonPressed();
		void Update();
		void Draw();
		void SetCleared(bool isCleared) { stageCleared = isCleared; }
		Retry::GameScenes GetButtonStage() { return stage; }
	private:
		Retry::GameScenes stage;
		math::vec2 position;
		Retry::Texture posibleTexture;
		Retry::Texture lockedTexture;
		Retry::Texture completeTexture;
		double width = 200;
		double height = 200;
		bool stageCleared;
		bool buttonPressed = false;
		bool isLocked;
	};
	
	Retry::InputKey shutDownKey;

	Retry::Texture dataTransferHowToPlay;

	std::vector<QuestButton> questButtons;
	QuestButton endingButton;
	Retry::Texture how_to_quest1;
};
