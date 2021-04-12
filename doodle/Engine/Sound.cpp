/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Sound.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 04/10/2021
-----------------------------------------------------------------*/
#include "Sound.h"
#include "Engine.h"

void Retry::Sound::LoadSound(const std::string& file_path)
{
	soundBuffers.emplace_back();
	sf::SoundBuffer& buffer = soundBuffers.back();
	buffer.loadFromFile(file_path);
	sounds.emplace_back();
	sounds.back().setBuffer(buffer);
}

void Retry::Sound::PlaySound(int index)
{
	sounds[index].setBuffer(soundBuffers[index]);
	sounds[index].play();
}

void Retry::Sound::SetVolume(int index, float volume)
{
	sounds[index].setVolume(volume);
}
