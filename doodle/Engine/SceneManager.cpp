/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: SceneManager.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Engine.h"
#include "SceneManager.h"
#include "../Game/Splash.h"
#include "../Game/MainMenu.h"
#include "../Game/Stage1.h"
#include "../Game/Stage2.h"
#include "../Game/Stage3.h"
#include "../Game/GameOver.h"
#include "../Game/TestStage.h"
#include "../Game/Story.h"

namespace Retry 
{
	void SceneManager::Setup()
	{
		scenes[GameScenes::Splash] = std::make_unique<Splash>();
		scenes[GameScenes::Story] = std::make_unique<Story>();
		scenes[GameScenes::MainMenu] = std::make_unique<MainMenu>();
		scenes[GameScenes::Stage1] = std::make_unique<Stage1>();
		scenes[GameScenes::Stage2] = std::make_unique<Stage2>();
		scenes[GameScenes::Stage3] = std::make_unique<Stage3>();
		scenes[GameScenes::GameOver] = std::make_unique<GameOver>();
		scenes[GameScenes::TestStage] = std::make_unique<TestStage>();

		currentScene = scenes[GameScenes::MainMenu].get();
		queuedScene = scenes[GameScenes::MainMenu].get();
	}

	void SceneManager::Update() 
	{
		switch (state) 
		{
		case State::START:
			if(scenes.empty() == true)
			{
				Engine::GetLogger().LogError("Empty Scenes");
			}
			else
			{
				state = State::LOAD;
			}
			break;
		case State::LOAD:
			Engine::GetLogger().LogDebug("Load " + currentScene->GetName());
			currentScene->Load();
			state = State::UPDATE;
			break;
		case State::UPDATE:
			currentScene->Update();
			currentScene->Draw();
			if (currentScene != queuedScene) 
			{
				state = State::UNLOAD;
			}
			break;
		case State::UNLOAD:
			Engine::GetLogger().LogDebug("Unload " + currentScene->GetName());
			currentScene->Unload();

			if (queuedScene == nullptr)
			{
				state = State::SHUTDOWN;
			}
			else 
			{
				currentScene = queuedScene;
				state = State::LOAD;
			}
			break;
		case State::SHUTDOWN: 
			state = State::EXIT;
			break;
		case State::EXIT:
			break;
		}
		
	}

	void SceneManager::setNextScene(GameScenes scene) 
	{
		queuedScene = scenes[scene].get();
	}

	void SceneManager::setGameOver(GameScenes currScene)
	{
		queuedScene = scenes[GameScenes::GameOver].get();
		queuedScene->prevScene = currScene;
	}


	void SceneManager::Shutdown()
	{
		queuedScene = nullptr;
	}

	void SceneManager::ReloadScene()
	{
		state = State::UNLOAD;
	}
	
}