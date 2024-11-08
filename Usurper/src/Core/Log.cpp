#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Usurper {

	std::shared_ptr<spdlog::logger> Log::s_Logger;


	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		Log::s_Logger = spdlog::stdout_color_mt("Usurper");
		Log::s_Logger->set_level(spdlog::level::trace);
	}
}
