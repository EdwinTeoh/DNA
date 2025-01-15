#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

 namespace DNA {
	class DNA_API Log
	{
		static std::shared_ptr<spdlog::logger> _core_logger;
		static std::shared_ptr<spdlog::logger> _client_logger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _core_logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _client_logger;  }
	};
}

 // Core macros
#define DNA_CORE_ERROR(...) ::DNA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DNA_CORE_WARN(...)  ::DNA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DNA_CORE_INFO(...)  ::DNA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DNA_CORE_TRACE(...) ::DNA::Log::GetCoreLogger()->trace(__VA_ARGS__)

 // Client macros
#define DNA_ERROR(...)      ::DNA::Log::GetClientLogger()->error(__VA_ARGS__)
#define DNA_WARN(...)       ::DNA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DNA_INFO(...)       ::DNA::Log::GetClientLogger()->info(__VA_ARGS__)
#define DNA_TRACE(...)      ::DNA::Log::GetClientLogger()->trace(__VA_ARGS__)

// Macro has the benefit of stripping from distribution builds via
/*
if dist build
#define DNA_CORE_INFO
*/