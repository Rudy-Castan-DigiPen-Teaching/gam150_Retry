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
		doodle::push_settings();
		doodle::apply_translate(position.x, position.y);
		doodle::draw_image(image, 0,0);
		doodle::pop_settings();
	}

	void Texture::Draw(math::vec2 position, math::ivec2 texelPos, math::ivec2 frameSize) {
	    doodle::push_settings();
		doodle::apply_translate(position.x, position.y);
	    doodle::draw_image(image, 0, 0, static_cast<double>(frameSize.x), static_cast<double>(frameSize.y), texelPos.x, texelPos.y);
	    doodle::pop_settings();
	}

	math::ivec2 Texture::getSize() 
	{
		return math::ivec2{ image.GetWidth(), image.GetHeight() };
	}
};