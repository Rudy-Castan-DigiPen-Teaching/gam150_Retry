/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Window.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Window.h"
#include <doodle/drawing.hpp>
#include <doodle/window.hpp>

namespace Retry 
{
	void Window::Init(std::string windowName)
	{
		doodle::create_window(windowName, 1440, 810);
		windowSize = { 1440,810 };

		doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	}

	void Window::Update() 
	{
		doodle::update_window();
	}

	math::ivec2 Window::GetSize()
	{
		return windowSize;
	}
}