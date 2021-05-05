/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: TestStage.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/28/2021
-----------------------------------------------------------------*/
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

    TestObject test1;             // = player
    Retry::Object test2;          // 부동 물체 

public:
    TestStage();
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Test Stage"; };
};