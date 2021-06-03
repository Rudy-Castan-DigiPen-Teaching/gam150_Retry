/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Sprite.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once

#include <string>
#include "Texture.h"
#include "Animation.h"

namespace Retry 
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();
		void Load(const std::filesystem::path& texturePath, math::ivec2 hotspot);
		void Load(const std::filesystem::path& spriteInfoFile);
		void Draw(math::vec2 position);
		void PlayAnimation(int anim);
		void Update(double dt);
		bool IsAnimationDone();
		math::ivec2 GetHotSpot();
		math::ivec2 GetFrameSize();
		math::ivec2 GetTextureSize();
	private:
		math::ivec2 GetFrameTexel(int frameNum) const;

		int currAnim;
		std::vector<Animation*> animations;
		math::ivec2 frameSize;
		std::vector<math::ivec2> frameTexel;

		Texture texture;
		math::ivec2 hotSpot;
	};
}