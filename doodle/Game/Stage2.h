#pragma once
#include <doodle/Input.hpp>
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"

class Stage2 : public Retry::Scene
{
private:

public:
    Stage2();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Stage2"; };
};