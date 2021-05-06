#include "../Engine/Object.h"
#include "../Engine/Sprite.h"
#include "../Engine/Engine.h"
#pragma once

class Hacker_Stage1 : public Retry::Object
{

public:
	Hacker_Stage1(math::vec2 initpos);
	void Load() override;
	void Update() override;
	void Draw() override;

private:
	math::vec2 initPos = { static_cast<double>(Engine::GetWindow().GetSize().x / 2) ,  static_cast<double>(Engine::GetWindow().GetSize().y) };
	Retry::Sprite sprite;
};