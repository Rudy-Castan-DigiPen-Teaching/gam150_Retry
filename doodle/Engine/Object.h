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
		double width{ 50 };
		double height{ 50 };
		math::vec2 hotspot{ width / 2.0, height / 2.0 };

	public:
		Object() = default;
		Object(math::vec2 pos, double w, double h, math::vec2 hotspot) : position(pos), width(w), height(h), hotspot(hotspot) {}
		Object(math::vec2 pos, double w, double h) : position(pos), width(w), height(h) { hotspot = { width / 2.0, height / 2.0 }; }
		Object(math::vec2 pos, double size) : Object(pos, size, size) {}
		Object(math::vec2 pos) : Object(pos, 50) {}
		~Object() {}

		virtual void Load();
		virtual void Update();
		virtual void Draw() const;

		bool CollideWith(const Object& obj);

		void SetPosition(math::vec2 newPos) { position = newPos; }
		void UpdatePosition(math::vec2 v) { position += v; }
		math::vec2 GetPosition() const { return position; }
		math::vec2 GetHotspot() const { return hotspot; }
		math::vec2 GetSize() const { return math::vec2{ width, height }; }
	};
}

