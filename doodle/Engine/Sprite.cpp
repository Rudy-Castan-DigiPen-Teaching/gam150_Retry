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
#include <fstream>
#include "Engine.h"

namespace Retry
{
	Sprite::Sprite() {}

	//void Sprite::Load(const std::filesystem::path& texturePath) 
	//{
	//	texture.Load(texturePath);
	//	hotSpot = texture.getSize() / 2;
	//}

	Sprite::~Sprite() {
		for (Animation* anim : animations) {
			delete anim;
		}
		animations.clear();
	}

	void Sprite::Load(const std::filesystem::path& texturePath, math::ivec2 hotspot)
	{
		texture.Load(texturePath);
		hotSpot = hotspot;
	}

	void Sprite::Load(const std::filesystem::path& spriteInfoFile)
	{
		frameTexel.clear();
		if (spriteInfoFile.extension() == ".png")
		{
			texture.Load(spriteInfoFile);
			hotSpot = texture.getSize() / 2;
			return;
		}
		if (spriteInfoFile.extension() != ".spt") {
			throw std::runtime_error("Bad Filetype.  " + spriteInfoFile.generic_string() + " not a sprite info file (.spt)");
		}
		std::ifstream inFile(spriteInfoFile);

		if (inFile.is_open() == false) {
			throw std::runtime_error("Failed to load " + spriteInfoFile.generic_string());
		}

		std::string text;
		inFile >> text;
		texture.Load(text);
		frameSize = texture.getSize();

		inFile >> text;
		while (inFile.eof() == false) {
			if (text == "FrameSize") {
				inFile >> frameSize.x;
				inFile >> frameSize.y;
			} else if (text == "NumFrames") {
				int numFrames;
				inFile >> numFrames;
				for (int i = 0; i < numFrames; i++) {
					frameTexel.push_back({ frameSize.x * i, 0 });
				}
			} else if (text == "Frame") {
				int frameLocationX, frameLocationY;
				inFile >> frameLocationX;
				inFile >> frameLocationY;
				frameTexel.push_back({ frameLocationX, frameLocationY });
			} else if (text == "HotSpot") {
				int hotSpotX, hotSpotY;
				inFile >> hotSpotX;
				inFile >> hotSpotY;
				hotSpot = { hotSpotX, hotSpotY };
			}
			else if (text == "Anim") {
				std::string anim = "";
				inFile >> anim;
				animations.push_back(new Animation(anim));
			}
			else {
				Engine::GetLogger().LogError("Unknown spt command " + text);
			}
			inFile >> text;
		}
		if (frameTexel.empty() == true) {
			frameTexel.push_back({ 0,0 });
		}
	}

	void Sprite::Update(double dt) {
		animations[currAnim]->Update(dt);
	}

	bool Sprite::IsAnimationDone()
	{
		if (animations[currAnim]->IsAnimationDone() == true)
		{
			return true;
		}

		return false;
	}
	
	void Sprite::Draw(math::vec2 position)
	{
		if (frameTexel.empty())
		{
			texture.Draw(position - hotSpot);
		}
		else
		{
			texture.Draw(position - hotSpot, frameTexel[animations[currAnim]->GetDisplayFrame()], frameSize);
		}
	}

	void Sprite::PlayAnimation(int anim) {
		if (anim >= 0 && anim < animations.size()) {
			currAnim = anim;
			animations[currAnim]->ResetAnimation();
		}
		else {
			currAnim = 0;
			Engine::GetLogger().LogError("Given animation is not valid");
		}
	}
	
	math::ivec2 Sprite::GetHotSpot()
	{
		return hotSpot;
	}

	math::ivec2 Sprite::GetTextureSize()
	{
		return texture.getSize();
	}

	math::ivec2 Sprite::GetFrameSize()
	{
		return frameSize;
	}

	math::ivec2 Sprite::GetFrameTexel(int frameNum) const
	{
		if (frameNum >= 0 && frameNum < frameTexel.size())
		{
			return frameTexel[frameNum];
		}
		else
		{
			Engine::GetLogger().LogDebug("Invalid FrameTexel index");
			return frameTexel[0];
		}
	}
}