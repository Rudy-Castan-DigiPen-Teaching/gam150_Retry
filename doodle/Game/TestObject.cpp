/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: TestObject.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
#include "TestObject.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>

TestObject::TestObject(math::vec2 initpos, int size) : Object(initpos, size),
moveUpKey(Retry::InputKey::Keyboard::W), moveDownKey(Retry::InputKey::Keyboard::S), moveLeftKey(Retry::InputKey::Keyboard::A), moveRightKey(Retry::InputKey::Keyboard::D){}

void TestObject::Update() 
{
	SetPosition({ static_cast<double>(doodle::get_mouse_x()) - (Object::GetSize().x / 2), static_cast<double>(doodle::get_mouse_y()) - (Object::GetSize().y / 2) });
}

void TestObject::Draw()
{
	doodle::push_settings();
	doodle::draw_rectangle(Object::GetPosition().x, Object::GetPosition().y, Object::GetSize().x);
	doodle::pop_settings();
}