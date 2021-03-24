/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Window.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once
#include <string>

#include "Vec2.h"

namespace Retry
{
	class Window
	{
	public:
		void Init(std::string windowName);
		void Update();
		math::ivec2 GetSize();

	private:
		math::ivec2 windowSize;
	};
};