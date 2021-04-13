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

		if (position.x + width >= objCorner.x &&
			position.x <= objCorner.x + obj.GetSize().x &&
			position.y + height >= objCorner.y &&
			position.y <= objCorner.y + obj.GetSize().y)
		{
			return true;
		}
		return false;
	}
}