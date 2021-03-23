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
	// 루디 OOP에 있던 Scene.h 이게 걍 GameState.h 대신한다 생각하면 될거같아
	void Sprite::Draw(math::vec2 position)
	{
		texture.Draw(position - hotSpot);
	}

	math::ivec2 Sprite::getTextureSize()
	{
		return texture.getSize();
	}
}