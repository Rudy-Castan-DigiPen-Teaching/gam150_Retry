#pragma once
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include <doodle/input.hpp>

class Stage1 : public Retry::Scene
{
private:
    
public:
    Stage1();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Stage1"; };
};