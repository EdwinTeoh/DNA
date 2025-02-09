#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DNA {
	std::shared_ptr<spdlog::logger> Log::_core_logger;
	std::shared_ptr<spdlog::logger> Log::_client_logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_core_logger = spdlog::stdout_color_mt("DNA");
		_core_logger->set_level(spdlog::level::trace);

		_client_logger = spdlog::stdout_color_mt("App");
		_client_logger->set_level(spdlog::level::trace);
	}
}