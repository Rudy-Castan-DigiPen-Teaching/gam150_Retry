#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"

class TestObject : public Retry::Object
{
private:

	Retry::InputKey moveUpKey;
	Retry::InputKey moveDownKey;
	Retry::InputKey moveLeftKey;
	Retry::InputKey moveRightKey;

public:
	TestObject(math::vec2 initpos, int size);

	void Update() override;
	void Draw() const override;
};