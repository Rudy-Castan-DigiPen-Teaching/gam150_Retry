/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: ConsoleMain.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Sketch.h"
#include "Engine/Engine.h"
#include <doodle/window.hpp>
#include <exception>
#include <iostream>

int main(void)
try
{
    Engine& engine = Engine::Instance();
    engine.Init("NetWorker");

    while (!doodle::is_window_closed())
    {
        engine.Update();
        //doodle::update_window();
        //sketch.draw();
    }
    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what() << "\n";
    return -1;
}
