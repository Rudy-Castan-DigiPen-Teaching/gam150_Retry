/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Logger.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 03/23/2021
-----------------------------------------------------------------*/

#pragma once

#include <string>

namespace Retry
{
	class Logger
	{
	public:
		enum class Severity
		{
			Debug, Event, Error
		};

		Logger(Severity severity);
		~Logger();
		void LogDebug(std::string text) { Log(Severity::Debug, text); }
		void LogEvent(std::string text) { Log(Severity::Event, text); }
		void LogError(std::string text) { Log(Severity::Error, text); }
	private:
		void Log(Severity sev, std::string displayText);
		Severity minLevel;
	};
}