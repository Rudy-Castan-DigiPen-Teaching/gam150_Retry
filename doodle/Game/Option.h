/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Option.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 06/09/2021
-----------------------------------------------------------------*/
#pragma once

#include "../Engine/Scene.h"
#include "../Engine/Button.h"
#include "../Engine/Sound.h"
#include "../Engine/Object.h"

class Option : public Retry::Scene
{
private:
	Button backButton;
	Retry::Sound sound;

	Retry::Object sfxVolumeKey;
	Retry::Object musicVolumeKey;

	static constexpr double minimum = 360;
	static constexpr double maximum = 1080;
	static constexpr double length = maximum - minimum;

	Retry::Texture sfxLetterTexture;
	Retry::Texture musicLetterTexture;
	
	Retry::Texture sfxBarTexture;
	Retry::Texture musicBarTexture;

	Retry::Sprite sfxButtonSprite;
	Retry::Sprite musicButtonSprite;
	
	enum SoundIndex
	{
		Click
	};

	bool IsMouseOnObject(Retry::Object object);
public:
	Option();
	void Load() override;
	void Update(double dt) override;
	void Unload() override;
	void Draw() override;
	std::string GetName() override { return "Option"; }
};