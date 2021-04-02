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
		doodle::draw_rectangle(position.x - hotspot.x, position.y - hotspot.y, width, height);
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





/*

class DataaBox : public Object
{
private:
	DataKind data;

public:
	enum class DataKind {
		
		red,
		green,
		blue

	}

	DataaBox(DataKind data) : data(data) {}



*/