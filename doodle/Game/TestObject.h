/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: TestObject.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
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