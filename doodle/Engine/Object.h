/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Object.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/27/2021
-----------------------------------------------------------------*/
#pragma once
#include "Vec2.h"
#include "Sprite.h"
#include <doodle/environment.hpp> 
#include <doodle/drawing.hpp>

namespace Retry
{
	class Object
	{
	protected:
		math::vec2 position{ 0 };
		int width{ 50 };
		int height{ 50 };
		math::ivec2 hotspot{ width / 2, height / 2 };

	public:
		Object() = default;
		Object(math::vec2 pos, int w, int h, math::ivec2 hotspot) : position(pos), width(w), height(h), hotspot(hotspot) {}
		Object(math::vec2 pos, int w, int h) : position(pos), width(w), height(h) { hotspot = { width / 2, height / 2 }; }
		Object(math::vec2 pos, int size) : Object(pos, size, size) {}
		Object(math::vec2 pos) : Object(pos, 50) {}
		~Object() {}

		virtual void Load();
		virtual void Update();
		virtual void Draw();

		bool CollideWith(const Object& obj);

		void SetPosition(math::vec2 newPos) { position = newPos; }
		void SetSize(math::ivec2 newSize) { width = newSize.x; height = newSize.y; }
		void UpdatePosition(math::vec2 v) { position += v; }
		math::vec2 GetPosition() const { return position; }
		math::ivec2 GetHotspot() const { return hotspot; }
		math::ivec2 GetSize() const { return math::ivec2{ width, height }; }
	};
}

