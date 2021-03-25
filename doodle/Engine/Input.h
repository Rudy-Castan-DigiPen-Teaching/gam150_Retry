/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Input.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/25/2021
-----------------------------------------------------------------*/
#pragma once
#include <vector>

namespace Retry
{
    class InputKey
    {
    public:
        enum class Keyboard
        {
            None, Enter, Escape, W, A, S, D, Count
        };

        InputKey(Keyboard button);
        bool IsKeyDown() const;
        bool IsKeyReleased() const;

    private:
        Keyboard button;
    };

    class Input
    {
    public:
        Input();
        bool IsKeyDown(InputKey::Keyboard key) const;
        bool IsKeyReleased(InputKey::Keyboard key) const;
        void SetKeyDown(InputKey::Keyboard key, bool value);
        void Update();
    private:
        std::vector<bool> KeyDown;
        std::vector<bool> wasKeyDown;
    };





}
