/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: InputDoodle.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/25/2021
-----------------------------------------------------------------*/
#include <doodle/input.hpp>
#include "Input.h"
#include "Engine.h"

Retry::InputKey::Keyboard DoodleKeyToRetryKey(doodle::KeyboardButtons button)
{
    if (button == doodle::KeyboardButtons::Enter)
    {
        return Retry::InputKey::Keyboard::Enter;
    }
    else if (button == doodle::KeyboardButtons::Escape)
    {
        return Retry::InputKey::Keyboard::Escape;
    }
    else if (button == doodle::KeyboardButtons::W)
    {
        return  Retry::InputKey::Keyboard::W;
    }
    else if (button == doodle::KeyboardButtons::S)
    {
        return  Retry::InputKey::Keyboard::S;
    }
    else if (button == doodle::KeyboardButtons::A)
    {
        return  Retry::InputKey::Keyboard::A;
    }
    else if (button == doodle::KeyboardButtons::D)
    {
        return  Retry::InputKey::Keyboard::D;
    }
    return Retry::InputKey::Keyboard::None;
}

void on_key_pressed(doodle::KeyboardButtons doodleButton)
{
    Retry::InputKey::Keyboard button = DoodleKeyToRetryKey(doodleButton);

    if (button != Retry::InputKey::Keyboard::None)
    {
        Engine::GetInput().SetKeyDown(button, true);
        Engine::GetLogger().LogDebug("on_key_pressed");
    }
}

void on_key_released(doodle::KeyboardButtons doodleButton)
{
    Retry::InputKey::Keyboard button = DoodleKeyToRetryKey(doodleButton);

    if (button != Retry::InputKey::Keyboard::None)
    {
        Engine::GetInput().SetKeyDown(button, false);
        Engine::GetLogger().LogDebug("on_key_released");
    }
}


void on_mouse_pressed(doodle::MouseButtons button)
{
    if (button == doodle::MouseButtons::Left)
    {
        Engine::GetMouseInput().setMousePressed(true);
        Engine::GetLogger().LogDebug("on_mouse_pressed");
    }

}

void on_mouse_released(doodle::MouseButtons button)
{
    if (button == doodle::MouseButtons::Left)
    {
        Engine::GetMouseInput().setMousePressed(false);
        Engine::GetLogger().LogDebug("on_mouse_released");
    }

}