#include "Log.h"

void Log::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	Enginelogger = spdlog::stdout_color_mt("ENGINE");
	Enginelogger->set_level(spdlog::level::level_enum::info);

	GE_LOG("Initialized log system successfully. Engine version : {0}", GE_VERSION);
}