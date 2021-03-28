#pragma once
#pragma once
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"    // Scene (Base class)
#include "../Engine/Input.h"

#include "../Engine/Object.h"
#include "TestObject.h"

class TestStage : public Retry::Scene
{
private:
    Retry::InputKey StageNext;

    TestObject test1;
    Retry::Object test2;

public:
    TestStage();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Stage1"; };
};