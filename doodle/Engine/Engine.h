#pragma once
#include <string>
// ¿Í~~

class Engine
{
public:

	static Engine& Instance() { static Engine instance;  return instance; }

	void Init(std::string windowName);
	void Shutdown();
	void Update();
	bool hasGameEnded();

private:
	Engine();
	~Engine();

};