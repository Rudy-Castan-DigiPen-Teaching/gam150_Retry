/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage2.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 03/23/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Input.h"
#include "../Engine/Engine.h" // GetLogger
#include "../Engine/Scene.h"
#include "Player_Stage2.h"
#include "DataBox.h"
#include "DataBoard.h"

class Stage2 : public Retry::Scene
{
private:
    Player_Stage2 player;
    std::vector<DataBox> dataBoxes;
    std::vector<DataBoard> dataBoard;
    int stackedData;
    int currTransferNum;

    int maxDataNum = 1;
    static constexpr int goalTranasferNum = 5;

    double timer;
    constexpr static int timeLimit = 60;

    bool gameStarted;
    bool stageCleared;
	
    Retry::InputKey StageNext;
    Retry::InputKey StageReload;
public:
    Stage2();

    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Stage2"; };

    static constexpr double floor = 200;
};