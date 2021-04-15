#include "TestObject.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>

TestObject::TestObject(math::vec2 initpos, int size) : Object(initpos, size),
moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S), moveLeftKey(Retry::InputKey::Keyboard::A), moveRightKey(Retry::InputKey::Keyboard::D){}

void TestObject::Update() 
{
	SetPosition({ static_cast<double>(doodle::get_mouse_x()) - (Object::GetSize().x / 2), static_cast<double>(doodle::get_mouse_y()) - (Object::GetSize().y / 2) });
}

void TestObject::Draw() const
{
	doodle::push_settings();
	doodle::draw_rectangle(Object::GetPosition().x, Object::GetPosition().y, Object::GetSize().x);
	doodle::pop_settings();
}