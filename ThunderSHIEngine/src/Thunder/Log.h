#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Thunder
{
	class THUNDER_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define	TE_CORE_ERROR(...)	::Thunder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define	TE_CORE_WARN(...)	::Thunder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define	TE_CORE_INFO(...)	::Thunder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define	TE_CORE_TACE(...)	::Thunder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define	TE_CORE_FATAL(...)	::Thunder::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//Client log macros
#define	TE_CLIENT_ERROR(...)	::Thunder::Log::GetClientLogger()->error(__VA_ARGS__)
#define	TE_CLIENT_WARN(...)		::Thunder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define	TE_CLIENT_INFO(...)		::Thunder::Log::GetClientLogger()->info(__VA_ARGS__)
#define	TE_CLIENT_TACE(...)		::Thunder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define	TE_CLIENT_FATAL(...)	::Thunder::Log::GetClientLogger()->fatal(__VA_ARGS__)
