#pragma once

#include <string>
#include "Texture.h"

namespace Retry 
{
	class Sprite
	{
	public:
		Sprite();
		void Load(const std::filesystem::path& texturePath);
		void Load(const std::filesystem::path& texturePath, math::ivec2 hotspotPos);
		void Draw(math::vec2 position);
		math::ivec2 getTextureSize();
	private:
		Texture texture;
		math::ivec2 hotSpot;
	};


}