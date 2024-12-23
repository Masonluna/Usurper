#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>



namespace Usurper {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }


	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};


}

#ifndef US_LOG
	#define US_LOG
	#define US_ERROR(...) ::Usurper::Log::GetLogger()->error(__VA_ARGS__)
	#define US_TRACE(...) ::Usurper::Log::GetLogger()->trace(__VA_ARGS__)
	#define US_INFO(...)  ::Usurper::Log::GetLogger()->info(__VA_ARGS__)
	#define US_WARN(...)  ::Usurper::Log::GetLogger()->warn(__VA_ARGS__)
	#define US_FATAL(...) ::Usurper::Log::GetLogger()->critical(__VA_ARGS__)
#endif