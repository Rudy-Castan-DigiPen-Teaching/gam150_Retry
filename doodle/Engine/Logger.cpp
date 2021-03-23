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
			}
		
			std::cout << displayText << std::endl;
		}
	}
}
