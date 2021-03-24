/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Splash.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Engine.h" // GetEngine
#include "../Engine/Scene.h"
#include "../Engine/Texture.h"
#include <doodle/input.hpp>

class Splash : public Retry::Scene
{
private:
    Retry::Texture Logo;
public:
    Splash();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Splash"; };
};
	