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
		math::vec2 position;
		math::vec2 hotspot;
		double width;
		double height;

	public:
		Object(math::vec2 pos, double size) : position(pos), width(size), height(size) {}
		Object(math::vec2 pos, double w, double h) : position(pos), width(w), height(h) {}
		~Object() {}

		virtual void Update();
		virtual void Draw() const;

		bool CollideWith(Object& obj);

		void SetPosition(math::vec2 newPos) { position = newPos; }
		math::vec2 GetPosition() const { return position; }
		math::vec2 GetHotspot() const { return hotspot; }
		math::vec2 GetSize() const { return math::vec2{ width, height }; }
	};
}

