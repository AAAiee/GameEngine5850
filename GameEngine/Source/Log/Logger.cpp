#include "Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

GME::Logger::Logger()
{
	engineLogger = spdlog::stdout_color_mt("EngineLogger");
	gameLogger = spdlog::stdout_color_mt("GameLogger");
	setLogLevel(spdlog::level::info);
	spdlog::set_pattern("%^[%T] %n: %v%$");
}

void GME::Logger::setLogLevel(spdlog::level::level_enum level)
{
	spdlog::set_level(level);
}

const std::shared_ptr<spdlog::logger>& GME::Logger::getEngineLogger() const
{
	return Logger::getLoggerInstance().engineLogger;

}

const std::shared_ptr<spdlog::logger>& GME::Logger::getGameLogger() const
{
	return Logger::getLoggerInstance().gameLogger;
}
