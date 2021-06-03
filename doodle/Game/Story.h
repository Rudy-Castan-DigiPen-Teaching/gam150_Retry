/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Story.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 04/26/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Engine.h"   // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"
#include "../Engine/DialogueManager.h"
#include "../Engine/Texture.h"
#include <vector>

enum class cutscene
{   
    boring,
    surprise,
    number_fall,
    number_surprise,
    number,
    calling,
    calling_hello,
    what,
    network,
    count
};

class Story : public Retry::Scene
{
private:
    Retry::InputKey mainmenu;
    DialogueManager dialogueManager;
    bool end = false;
public:
    Story();
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Story"; }
    std::vector<Retry::Texture> cutscenes;
    Retry::Texture* currscene = nullptr;
};
