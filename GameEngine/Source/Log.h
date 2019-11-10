#pragma once

#include "GameEngine.h"

#include "Helpers/Singleton.h"

#include <memory>

/// plog
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define GE_LOG(...) Log::Get().Enginelogger->info(__VA_ARGS__);

namespace spdlog
{
	class logger;
}

class GE_API Log : public Singleton<Log>
{
public:
	void Init();


	std::shared_ptr<spdlog::logger> Enginelogger;
};

