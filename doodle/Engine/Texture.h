/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Texture.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once
#include <doodle/image.hpp>
#include "Vec2.h"

namespace Retry
{
	class Texture
	{
	public:
		Texture();
		void Load(const std::filesystem::path& filePath);
		void Draw(math::vec2 position);
        void Draw(math::vec2 position, math::ivec2 texelPos, math::ivec2 frameSize);
		math::ivec2 getSize();
	private:
		doodle::Image image;
	};
};