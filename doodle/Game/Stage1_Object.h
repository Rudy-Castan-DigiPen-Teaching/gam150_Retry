/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Stage1_Object.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park
Creation date: 04/01/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "../Engine/Input.h"

class Stage1_Object : public Retry::Object
{
	private :

	public:
		Stage1_Object(math::ivec2 initpos, double w, double h);
		~Stage1_Object() {}

		void Update(int num);
		void Draw(int num) const;
};
