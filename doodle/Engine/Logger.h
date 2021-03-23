#pragma once

#include <string>

namespace Retry
{
	class Logger
	{
	public:
		enum class Severity
		{
			Debug, Event,
		};

		Logger(Severity severity);
		~Logger();
		void LogDebug(std::string text) { Log(Severity::Debug, text); }
		void LogEvent(std::string text) { Log(Severity::Event, text); }
	private:
		void Log(Severity sev, std::string displayText);
		Severity minLevel;
	};
}