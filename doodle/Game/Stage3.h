#pragma once
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include <doodle/input.hpp>

class Stage3 : public Retry::Scene
{
private:
    //Retry::Texture Logo;
public:
    Stage3();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Stage3"; };
};