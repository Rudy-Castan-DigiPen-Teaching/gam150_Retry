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
#include <doodle/environment.hpp> 
#include <doodle/drawing.hpp> 

namespace Retry
{
	class Object
	{
	protected:
		math::vec2 position {0,0};
		double width = 50;
		double height = 50;

	public:
		Object(math::vec2 pos, double w, double h) : position(pos), width(w), height(h) {}
		~Object() {}

		virtual void Update() = 0;
		virtual void Draw() const = 0;

		math::vec2 GetPosition() { return position; }
		double GetWidth() { return width; }
		double GetHeight() { return height; }
	};
}

