/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: MainMenu.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 04/15/2021
-----------------------------------------------------------------*/
#pragma once

#include <vector>
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"
#include "../Engine/Button.h"
#include "../Engine/Sprite.h"
#include "Star.h"
#include <SFML/Audio/Music.hpp>
#include "../Engine/Sound.h"

class MainMenu : public Retry::Scene
{
private:
    std::vector<Button> buttons;
    Retry::Texture title;
    Retry::InputKey exitkey;
    sf::Music music;
    Retry::Sound sound;

    enum SoundIndex {
        click,
    };
    constexpr static int starNum = 600;
    std::vector<Star> stars{ starNum };

public:
    MainMenu();
    void Load() override;
    void Update(double dt) override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Main Menu"; };
};