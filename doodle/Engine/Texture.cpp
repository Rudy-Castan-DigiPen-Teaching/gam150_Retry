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