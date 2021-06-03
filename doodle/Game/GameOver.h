/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameOver.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/26/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Engine.h"   // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"
#include "../Engine/Button.h"
#include "../Engine/Sound.h"

class GameOver : public Retry::Scene
{
private:
    std::vector<Button> buttons;
    Retry::InputKey exitKey;

    Retry::Sound sound;

    enum SoundIndex {
        click,
    };
public:
    GameOver();
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Main Menu"; }
};