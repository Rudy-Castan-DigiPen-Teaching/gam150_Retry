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
#include "Player.h"
#include "DataBox.h"

class Stage2 : public Retry::Scene
{
private:
    Player player;
    std::vector<DataBox> dataBoxes;
    int stackedData;

    Retry::InputKey StageNext;
public:
    Stage2();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Stage2"; };
};

/*
* ¿ÞÂÊ¿¡ ½×¿©ÀÖ´Â ¹Ú½º Áß¿¡ ¹Ù´ÚÇÏ°í ´ê¾ÆÀÖ´Â°Å µû·Î »©¼­
* if (databox.Getposiiton().y == floor && player.) {
*
* }
*/