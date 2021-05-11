/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ending.h
Project: GAM150_Networker
Author: Team RETRY - Haeun Park
Creation date: 05/06/2021
-----------------------------------------------------------------*/
#include "../Engine/Input.h"
#include "../Engine/Scene.h"
#include "../Engine/Sprite.h"

class Ending : public Retry::Scene
{
private:
    Retry::Sprite texture;
public:
    Ending();
    void Load() override;
    void Update(double) override;
    void Unload() override;
    void Draw() override;
    std::string GetName() override { return "Ending"; }
};
