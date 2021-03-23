#include "Engine.h"

Engine::Engine() : logger(Retry::Logger::Severity::Debug){}

Engine::~Engine() {}

void Engine::Init(std::string windowName)
{
	logger.LogEvent("Engine Init");
	window.Init(windowName);
}

void Engine::Shutdown()
{
	logger.LogEvent("Engine Shutdown");
}

void Engine::Update()
{
	window.Update();
}

bool Engine::hasGameEnded() 
{
	return false;
}