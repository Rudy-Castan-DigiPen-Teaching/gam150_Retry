#pragma once
#include <string>
#include "Logger.h"
#include "Window.h"
// ¿Í~~

class Engine
{
public:

	static Engine& Instance() { static Engine instance;  return instance; }
	static Retry::Logger& GetLogger() { return  Instance().logger; };
	static Retry::Window& GetWindow() { return Instance().window; }

	void Init(std::string windowName);
	void Shutdown();
	void Update();
	bool hasGameEnded();

private:
	Engine();
	~Engine();

	Retry::Logger logger;
	Retry::Window window;
};