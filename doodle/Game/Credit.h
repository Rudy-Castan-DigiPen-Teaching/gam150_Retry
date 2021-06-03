/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Credit.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 05/13/2021
-----------------------------------------------------------------*/
#pragma once

#include <vector>
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"
#include "../Engine/Button.h"
#include "../Engine/Sprite.h"
#include "../Engine/Sound.h"
class Credit : public Retry::Scene
{
private:
    std::vector<Button> buttons;
    Retry::Sound sound;

    enum SoundIndex {
        click,
    };
public:
    Credit();
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Credit"; };
};