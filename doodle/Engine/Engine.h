/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Engine.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once
#include <string>
#include "Logger.h"
#include "Window.h"
#include "SceneManager.h"
#include "Input.h"
class Engine
{
public:

	static Engine& Instance() { static Engine instance;  return instance; }
	static Retry::Logger& GetLogger() { return  Instance().logger; }
	static Retry::Window& GetWindow() { return Instance().window; }
	static Retry::SceneManager& GetSceneManager() { return Instance().sceneManager; }
	static Retry::Input& GetInput() { return Instance().input; }

	void Init(std::string windowName);
	void Shutdown();
	void Update();
	bool hasGameEnded();

private:
	Engine();
	~Engine();

	Retry::Logger logger;
	Retry::Window window;
	Retry::SceneManager sceneManager;
	Retry::Input input;
};