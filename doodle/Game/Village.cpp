#include "Village.h"
#include "../Engine/Engine.h"
#include <doodle/Input.hpp>
#include <doodle/drawing.hpp>

Village::Village() : shutDownKey(Retry::InputKey::Keyboard::Escape)
{
	
}

void Village::Load()
{
	questButtons.push_back(QuestButton(math::vec2(Engine::GetWindow().GetSize().x - 150, Engine::GetWindow().GetSize().y * 0.8), Retry::GameScenes::Stage1));
	questButtons.push_back(QuestButton(math::vec2(Engine::GetWindow().GetSize().x - 150, Engine::GetWindow().GetSize().y * 0.5), Retry::GameScenes::Stage2));
	questButtons.push_back(QuestButton(math::vec2(Engine::GetWindow().GetSize().x - 150, Engine::GetWindow().GetSize().y * 0.2), Retry::GameScenes::Stage3));

	for (int i = 0; i < questButtons.size(); ++i)
	{
		if (Engine::GetSceneManager().StageCleared(questButtons[i].GetButtonStage()) == true)
		{
			questButtons[i].SetCleared(true);
		}
	}
}

void Village::Update(double)
{
	if (shutDownKey.IsKeyReleased() == true)
	{
		Engine::GetSceneManager().Shutdown();
	}
	for (int i = 0; i < questButtons.size(); ++i)
	{
		questButtons[i].Update();
		if (questButtons[i].IsButtonPressed() == true)
		{
			Engine::GetSceneManager().setNextScene(questButtons[i].GetButtonStage());
		}
	}
}

void Village::Unload()
{
	
}

void Village::Draw()
{
	doodle::clear_background(133, 230, 255);
	for (int i = 0; i < questButtons.size(); ++i)
	{
		questButtons[i].Draw();

		if (questButtons[i].IsMouseOn() == true)
		{
			switch (i)
			{
			case 0:
				doodle::draw_rectangle(50, 100, 1000, 610);
				break;
			case 1:
				doodle::draw_rectangle(50, 100, 1000, 610);
				break;
			case 2:
				doodle::draw_rectangle(50, 100, 1000, 610);
				break;
			}
		}
	}


}

Village::QuestButton::QuestButton(math::vec2 pos, Retry::GameScenes stage) : position(pos), stage(stage), stageCleared(false)
{
	
}

bool Village::QuestButton::IsMouseOn()
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

bool Village::QuestButton::IsButtonPressed()
{
	return buttonPressed;
}

void Village::QuestButton::Update()
{
	if (stageCleared == false && IsMouseOn() && Engine::GetMouseInput().IsMousePressed())
	{
		buttonPressed = true;
	}
	else
	{
		buttonPressed = false;
	}
}

void Village::QuestButton::Draw()
{
	doodle::push_settings();
	doodle::set_rectangle_mode(doodle::RectMode::Center);
	if (stageCleared == false)
	{
		if (IsMouseOn() == true)
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
