/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Village.cpp
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 05/03/2021
-----------------------------------------------------------------*/
#include "Village.h"
#include "../Engine/Engine.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>

Village::Village() : shutdownKey(Retry::InputKey::Keyboard::Escape)
{
}

void Village::Load()
{
	questButtons.push_back(QuestButton(math::vec2(), Stages::Stage1));
	questButtons.push_back(QuestButton(math::vec2(), Stages::Stage2));
	questButtons.push_back(QuestButton(math::vec2(), Stages::Stage3));

	for (QuestButton button : questButtons)
	{
		if (Engine::GetSceneManager().StageCleared(StageToGameScenes(button.GetButtonStage())) == true)
		{
			button.SetStageCleared(true);
		}
	}
}

void Village::Update()
{
	if (shutdownKey.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}

	
}

void Village::Unload()
{
	
}

void Village::Draw()
{
	doodle::clear_background(133, 230, 255);
}

Retry::GameScenes Village::StageToGameScenes(Stages stage)
{
	switch(stage)
	{
	case Stages::Stage1:
		return Retry::GameScenes::Stage1;
		break;
	case Stages::Stage2:
		return Retry::GameScenes::Stage2;
		break;
	case Stages::Stage3:
		return Retry::GameScenes::Stage3;
	}
}


Village::QuestButton::QuestButton(math::vec2 pos, Stages s) : position(pos), stage(s)
{
	
}

bool Village::QuestButton::isMouseOn()
{
	if (doodle::get_mouse_x() < position.x + width / 2 && 
		doodle::get_mouse_x() > position.x - width / 2 && 
		doodle::get_mouse_y() < position.y + height / 2 && 
		doodle::get_mouse_y() > position.y - height / 2)
	{
		return true;	
	}
	else
	{
		return false;
	}
}

void Village::QuestButton::Update()
{
	if (stageCleared == false)
	{
		if (isMouseOn() && Engine::GetMouseInput().IsMousePressed())
		{
			buttonPressed = true;
		}
		else
		{
			buttonPressed = false;
		}
	}
}


void Village::QuestButton::Draw()
{
	doodle::push_settings();
	doodle::set_rectangle_mode(doodle::RectMode::Center);
	if (stageCleared == false)
	{
		if (isMouseOn() == true)
		{
			doodle::set_fill_color(200);
		}
		else
		{
			doodle::set_fill_color(255);
		}
	}
	else
	{
		doodle::set_fill_color(100);
	}
	doodle::draw_rectangle(position.x, position.y, width, height);
	doodle::pop_settings();
}

bool Village::QuestButton::isPressed()
{
	return buttonPressed;
}
