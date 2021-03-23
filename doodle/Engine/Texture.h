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
		math::ivec2 getSize();
	private:
		doodle::Image image;
	};
};