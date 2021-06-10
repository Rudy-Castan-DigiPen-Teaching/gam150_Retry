/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Option.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 06/09/2021
-----------------------------------------------------------------*/
#include "Option.h"
#include "../Engine/Engine.h"
#include <doodle/input.hpp>

Option::Option() : backButton("assets/button_back.png", math::vec2(Engine::GetWindow().GetSize().x - 200, Engine::GetWindow().GetSize().y * 0.1)),
sfxVolumeKey(math::vec2{maximum, Engine::GetWindow().GetSize().y * 0.8}, 50, 100), musicVolumeKey(math::vec2{maximum, Engine::GetWindow().GetSize().y * 0.6}, 50, 100)
{
	prevScene = Retry::GameScenes::MainMenu;
}

void Option::Load()
{
	optionLetterTexture.Load("assets/option_word.png");
	sfxLetterTexture.Load("assets/option_sfx.png");
	musicLetterTexture.Load("assets/option_music.png");
	sfxBarTexture.Load("assets/sound_bar.png");
	musicBarTexture.Load("assets/sound_bar.png");
	sfxButtonSprite.Load("assets/sound_button.png");
	musicButtonSprite.Load("assets/sound_button.png");
	sound.LoadSound("assets/select_003.ogg");
	sound.SetVolume(Click, Retry::SoundOption::sfxVolume);
}

void Option::Update(double)
{
	backButton.Update();

	if (backButton.isButtonPressed() == true)
	{
		sound.SetVolume(Click, Retry::SoundOption::sfxVolume);
		sound.PlaySound(Click);
		Engine::GetSceneManager().setNextScene(Retry::GameScenes::MainMenu);
	}

	if (Engine::GetMouseInput().IsMousePressed()) {
		if (IsMouseOnObject(sfxVolumeKey))
		{
			sfxVolumeKey.SetPosition(math::vec2(doodle::get_mouse_x(), sfxVolumeKey.GetPosition().y));
		}
		else if (IsMouseOnObject(musicVolumeKey))
		{
			musicVolumeKey.SetPosition(math::vec2(doodle::get_mouse_x(), musicVolumeKey.GetPosition().y));
		}
	}
	if (sfxVolumeKey.GetPosition().x < minimum)
	{
		sfxVolumeKey.SetPosition(math::vec2(minimum, sfxVolumeKey.GetPosition().y));
	}
	if (sfxVolumeKey.GetPosition().x > maximum)
	{
		sfxVolumeKey.SetPosition(math::vec2(maximum, sfxVolumeKey.GetPosition().y));
	}
	if (musicVolumeKey.GetPosition().x < minimum)
	{
		musicVolumeKey.SetPosition(math::vec2(minimum, musicVolumeKey.GetPosition().y));
	}
	if (musicVolumeKey.GetPosition().x > maximum)
	{
		musicVolumeKey.SetPosition(math::vec2(maximum, musicVolumeKey.GetPosition().y));
	}

	Retry::SoundOption::sfxVolume = static_cast<float>((sfxVolumeKey.GetPosition().x - minimum) / length * 100.0);
	Retry::SoundOption::musicVolume = static_cast<float>((musicVolumeKey.GetPosition().x - minimum) / length * 100.0);
}

void Option::Unload()
{
	
}

void Option::Draw()
{
	doodle::clear_background(0);
	doodle::push_settings();
	optionLetterTexture.Draw(math::vec2{minimum - optionLetterTexture.getSize().x - 25, minimum * 1.9});
	sfxLetterTexture.Draw(math::vec2(minimum - sfxLetterTexture.getSize().x - 50, sfxVolumeKey.GetPosition().y - sfxLetterTexture.getSize().y / 2));
	musicLetterTexture.Draw(math::vec2(minimum - musicLetterTexture.getSize().x - 50, musicVolumeKey.GetPosition().y - musicLetterTexture.getSize().y / 2));
	sfxBarTexture.Draw(math::vec2(minimum, sfxVolumeKey.GetPosition().y - sfxBarTexture.getSize().y / 2));
	musicBarTexture.Draw(math::vec2(minimum, musicVolumeKey.GetPosition().y - musicBarTexture.getSize().y / 2));
	sfxButtonSprite.Draw(sfxVolumeKey.GetPosition());
	musicButtonSprite.Draw(musicVolumeKey.GetPosition());
	backButton.Draw();
	doodle::pop_settings();
}

bool Option::IsMouseOnObject(Retry::Object object)
{
	math::ivec2 objSize = object.GetSize();
	return doodle::get_mouse_x() > object.GetPosition().x - objSize.x / 2 &&
		doodle::get_mouse_x() < object.GetPosition().x + objSize.x / 2 &&
		doodle::get_mouse_y() > object.GetPosition().y - objSize.y / 2 &&
		doodle::get_mouse_y() < object.GetPosition().y + objSize.y / 2;
}
