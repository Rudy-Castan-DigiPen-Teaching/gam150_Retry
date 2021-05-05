/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Engine.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Engine.h"

Engine::Engine() : logger(Retry::Logger::Severity::Debug), lastTick(std::chrono::system_clock::now()) {}

Engine::~Engine() {}

void Engine::Init(std::string windowName)
{
	logger.LogEvent("Engine Init");
	window.Init(windowName);
	sceneManager.Setup();

	fpsCalcTime = lastTick;
}

void Engine::Shutdown()
{
	logger.LogEvent("Engine Shutdown");
}

void Engine::Update()
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	double dt = std::chrono::duration<double>(now - lastTick).count();

	lastTick = now;
	window.Update();
	sceneManager.Update(dt);
	input.Update();
	mouseInput.Update();

}

bool Engine::hasGameEnded() 
{
	return sceneManager.HasGameEnded();
}