#include "Window.h"
#include <doodle/drawing.hpp>
#include <doodle/window.hpp>

namespace Retry 
{
	void Window::Init(std::string windowName)
	{
		doodle::create_window(windowName, 1440, 810);
	}

	void Window::Update() 
	{
		doodle::update_window();
	}
	
}