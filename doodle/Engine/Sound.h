/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Sound.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 04/10/2021
-----------------------------------------------------------------*/
#pragma once
#include <SFML/Audio.hpp>
#include <vector>
namespace Retry
{
	class Sound
	{
		std::vector<sf::SoundBuffer> soundBuffers{};
		std::vector<sf::Sound> sounds{};

	public:
		void LoadSound(const std::string& file_path);
		void PlaySound(int index);
		void SetVolume(int index, float volume);
	};
}
