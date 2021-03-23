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

namespace Retry 
{
	void SceneManager::Setup()
	{
		//scenes[GameScenes::Splash] = std::make_unique<>   ***클래스 만들기***

		currentScene = scenes[GameScenes::Splash].get();
		queuedScene = scenes[GameScenes::Splash].get();
	}

	void SceneManager::Update() 
	{
		switch (state) 
		{
		case State::START:
			if(scenes.empty() == true)
			{
				Engine::GetLogger().LogError("Error");
			}
			else
			{
				state = State::LOAD;
			}
			break;
		case State::LOAD:
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
}