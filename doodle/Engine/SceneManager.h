/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: SceneManager.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once
#include "Scene.h"
#include <map>
#include <memory>

namespace Retry {
	enum class GameScenes
	{
		Splash, MainMenu, Level1, Level2, Level3,
	};

	class SceneManager
	{
	private:
		enum class State {
			START,
			LOAD,
			UPDATE,
			UNLOAD,
			SHUTDOWN,
			EXIT,
		};

		State state;
		Scene* currentScene{ nullptr };
		Scene* queuedScene{ nullptr };
		std::map<GameScenes, std::unique_ptr<Scene>> scenes{};

	public:
		SceneManager() = default;

		void Setup();
		void Update();
		void Draw() const;
		void setNextScene(GameScenes scene);
	};
}