/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Sprite.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Sprite.h"
#include <doodle/drawing.hpp>

namespace Retry
{
	Sprite::Sprite() {}

	void Sprite::Load(const std::filesystem::path& texturePath) 
	{
		texture.Load(texturePath);
		hotSpot = texture.getSize() / 2;
	}

	void Sprite::Load(const std::filesystem::path& texturePath, math::ivec2 hotspotPos)
	{
		texture.Load(texturePath);
		hotSpot = hotspotPos;
	}
	
	void Sprite::Draw(math::vec2 position)
	{
		texture.Draw(position - hotSpot);
	}

	math::ivec2 Sprite::getTextureSize()
	{
		return texture.getSize();
	}
}