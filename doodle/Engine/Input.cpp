/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Input.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/25/2021
-----------------------------------------------------------------*/
#include "Input.h"
#include "Engine.h"

Retry::InputKey::InputKey(Keyboard button) : button(button){}

bool Retry::InputKey::IsKeyDown() const
{
   return Engine::GetInput().IsKeyDown(button);
}

bool Retry::InputKey::IsKeyReleased() const
{
    return Engine::GetInput().IsKeyReleased(button);
}

/*----------input class----------------------------------------------------------*/
Retry::Input::Input()
{
    wasKeyDown.resize(static_cast<int>(InputKey::Keyboard::Count));
    KeyDown.resize(static_cast<int>(InputKey::Keyboard::Count));
}

bool Retry::Input::IsKeyDown(InputKey::Keyboard key) const
{
    return KeyDown[static_cast<int>(key)];
}

bool Retry::Input::IsKeyReleased(InputKey::Keyboard key) const
{
    return (wasKeyDown[static_cast<int>(key)] == true) && (KeyDown[static_cast<int>(key)] == false);
}

void Retry::Input::SetKeyDown(InputKey::Keyboard key, bool value)
{
    KeyDown[static_cast<int>(key)] = value;
}

void Retry::Input::Update()
{
    wasKeyDown = KeyDown;
}
