/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Logger.cpp
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#include "Logger.h"
#include <iostream>

namespace Retry 
{
	Logger::Logger(Logger::Severity severity) : minLevel(severity)
	{
	}

	Logger::~Logger() {}

	void Logger::Log(Logger::Severity sev, std::string displayText)
	{
		if (minLevel <= sev)
		{
			switch (sev)
			{
			case Severity::Debug:
				std::cout << "Debug\t";
				break;
			case Severity::Event:
				std::cout << "Event\t";
				break;
			case Severity::Error:
				std::cout << "Error\t";
				break;
			}
		
			std::cout << displayText << std::endl;
		}
	}
}
