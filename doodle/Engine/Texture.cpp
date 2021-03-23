/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Texture.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Texture.h"
#include <doodle/drawing.hpp>

namespace Retry {
	Texture::Texture() {}

	void Texture::Load(const std::filesystem::path& filePath)
	{
		image = doodle::Image{filePath};
	}

	void Texture::Draw(math::vec2 position)
	{
		doodle::draw_image(image, position.x, position.y);
	}

	math::ivec2 Texture::getSize() 
	{
		return math::ivec2{ image.GetWidth(), image.GetHeight() };
	}
};