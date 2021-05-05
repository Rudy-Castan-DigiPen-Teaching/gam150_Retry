/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Object.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#include "Engine.h"
#include "Object.h"
#include <doodle/drawing.hpp>

namespace Retry
{
	void Object::Update() {}

	void Object::Load() {}

	void Object::Draw() const
	{
		doodle::push_settings();
		doodle::apply_translate(position.x - hotspot.x, position.y - hotspot.y);
		doodle::draw_rectangle(0,0, width, height);
		doodle::pop_settings();
	}

	bool Object::CollideWith(const Object& obj)
	{
		math::vec2 corner = position - hotspot;
		math::vec2 objCorner = obj.GetPosition() - obj.GetHotspot();
		
		if (corner.x + width >= objCorner.x &&
			corner.x <= objCorner.x + obj.GetSize().x &&
			corner.y + height >= objCorner.y &&
			corner.y <= objCorner.y + obj.GetSize().y)
		{
			return true;
		}
		return false;
	}
}