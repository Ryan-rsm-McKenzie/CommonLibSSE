#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/L/LogEvent.h"

// clang format chokes hard on classes with attributes
#define SKSE_MAYBE_UNUSED [[maybe_unused]]
#define SKSE_MAKE_SOURCE_LOGGER(a_func, a_type)                           \
                                                                          \
	template <class... Args>                                              \
	struct SKSE_MAYBE_UNUSED a_func                                       \
	{                                                                     \
		a_func() = delete;                                                \
                                                                          \
		template <class T>                                                \
		a_func(                                                           \
			T&& a_fmt,                                                    \
			Args&&... a_args,                                             \
			stl::source_location a_loc = stl::source_location::current()) \
		{                                                                 \
			spdlog::log(                                                  \
				spdlog::source_loc{                                       \
					a_loc.file_name(),                                    \
					static_cast<int>(a_loc.line()),                       \
					a_loc.function_name() },                              \
				spdlog::level::a_type,                                    \
				std::forward<T>(a_fmt),                                   \
				std::forward<Args>(a_args)...);                           \
		}                                                                 \
	};                                                                    \
                                                                          \
	template <class T, class... Args>                                     \
	a_func(T&&, Args&&...) -> a_func<Args...>;

namespace SKSE
{
	namespace log
	{
		SKSE_MAKE_SOURCE_LOGGER(trace, trace);
		SKSE_MAKE_SOURCE_LOGGER(debug, debug);
		SKSE_MAKE_SOURCE_LOGGER(info, info);
		SKSE_MAKE_SOURCE_LOGGER(warn, warn);
		SKSE_MAKE_SOURCE_LOGGER(error, err);
		SKSE_MAKE_SOURCE_LOGGER(critical, critical);

		[[nodiscard]] std::optional<std::filesystem::path> log_directory();
	}

	void add_papyrus_sink(std::regex a_filter);
	void remove_papyrus_sink();
}

#undef SKSE_MAKE_SOURCE_LOGGER
#undef SKSE_MAYBE_UNUSED

#define _DMESSAGE(a_fmt, ...)
#define _VMESSAGE(a_fmt, ...)
#define _MESSAGE(a_fmt, ...)
#define _WARNING(a_fmt, ...)
#define _ERROR(a_fmt, ...)
#define _FATALERROR(a_fmt, ...)

#pragma deprecated("_DMESSAGE")
#pragma deprecated("_VMESSAGE")
#pragma deprecated("_MESSAGE")
#pragma deprecated("_WARNING")
#pragma deprecated("_ERROR")
#pragma deprecated("_FATALERROR")
