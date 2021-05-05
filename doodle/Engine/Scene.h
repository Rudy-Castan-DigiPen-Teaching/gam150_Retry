/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Scene.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once
#include <string>

namespace Retry {
    class SceneManager;

    enum class GameScenes;
	
    class Scene
    {
    public:
        Scene(){}

        virtual void Load() = 0;
        virtual void Update(double) = 0;
        virtual void Unload() = 0;
        virtual void Draw() = 0;
        virtual std::string GetName() = 0;

        virtual ~Scene() = default;
        Scene(const Scene& other) = default;
        //Scene(Scene&& other) noexcept = default;
        Scene& operator=(const Scene& other) = default;
        //Scene& operator=(Scene&& other) noexcept = default;

        GameScenes prevScene;
    };
}