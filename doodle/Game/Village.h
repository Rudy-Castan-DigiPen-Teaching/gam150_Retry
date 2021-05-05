/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Village.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 05/03/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Scene.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Input.h"
#include <vector>


class Village : public Retry::Scene
{
private:
    enum class Stages
    {
	    Stage1, Stage2, Stage3
    };
	
    class QuestButton
    {
    public:
        QuestButton(math::vec2 pos, Stages s);
        bool isMouseOn();
        bool isPressed();
        void Update();
        void Draw();
        void SetStageCleared(bool isCleared) { stageCleared = isCleared; }
        Stages GetButtonStage() { return stage; }
    private:
        math::vec2 position;
        double width = 200;
        double height = 200;
        bool stageCleared = false;
        bool buttonPressed = false;

        Stages stage;
        // Retry::Texture texture;
    };

    std::vector<QuestButton> questButtons;
	
	// Retry::Texture background;
	// Retry::Texture admin;

	// bool explainStage;

    Retry::InputKey shutdownKey;

    Retry::GameScenes StageToGameScenes(Stages stage);

public:
    Village();
    void Load() override;
    void Update() override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Village"; }
};
