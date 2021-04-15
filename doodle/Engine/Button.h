#pragma once
#include <string>
#include "Vec2.h"
class Button {

public:
	Button(std::string tex, math::vec2 pos, double width, double height);
	Button(std::string tex, double x, double y, double width, double height);
	Button(std::string tex, double x, double y, double width, double height, double fnt_size);
	bool isMouseOnButton();
	void Update();
	void Draw();
	void setFontSize(double size);
	bool isButtonPressed() { return buttonPressed; }

private:
	std::string text = "";
	double pos_x = 0;
	double pos_y = 0;
	double button_width = 30;
	double button_height = 30;
	double fnt_size = button_width / text.size();
	bool buttonPressed = false;

};