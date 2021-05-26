/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Star.h
Project: GAM150_Networker
Author: Haeun Park
Creation date: 05/26/2021
-----------------------------------------------------------------*/
#pragma once

class Star {
	double x;
	double y;
	double z;
	double radius = 8;

	double zSpeed = 300;

public:
	Star();
	void Update(double dt);
	void Draw();

private:
	//helper function
	double map(double val, double v_low, double v_up, double new_low, double new_up);
};