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
#include "../Engine/Scene.h"
#include "../Engine/Sound.h"
#include "Player_Stage2.h"
#include "Hacker_Stage2.h"
#include "DataBox.h"
#include "DataBoard.h"

class Stage2 : public Retry::Scene
{
private:
    Player_Stage2 player;
    Hacker_Stage2 hacker;
    std::vector<DataBox> dataBoxes;
    std::vector<DataBoard> dataBoard;
    int stackedData;
    int currTransferNum;
	
    int maxDataNum = 1;
    static constexpr int goalTranasferNum = 3;

    double timer;
    constexpr static int timeLimit = 60;

    bool stageStarted;
    bool stageCleared;
	
    Retry::InputKey StageNext;
    Retry::InputKey StageReload;
    Retry::InputKey StageStart;
    Retry::InputKey RolebackMenu;

    Retry::Sound sound;

	enum SoundIndex
	{
		StackBox,
		TransferData,
		SteelData,
		RefillData
	};
public:
    Stage2();

    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;
	
    std::string GetName() override { return "Stage2"; };

    static constexpr double floor = 200;
};