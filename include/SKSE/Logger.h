#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/L/LogEvent.h"

#define SKSE_MAKE_SOURCE_LOGGER(a_func, a_type)                           \
                                                                          \
	template <class... Args>                                              \
	struct [[maybe_unused]] a_func                                        \
	{                                                                     \
		a_func() = delete;                                                \
                                                                          \
		explicit a_func(                                                  \
			fmt::format_string<Args...> a_fmt,                            \
			Args&&... a_args,                                             \
			std::source_location a_loc = std::source_location::current()) \
		{                                                                 \
			spdlog::log(                                                  \
				spdlog::source_loc{                                       \
					a_loc.file_name(),                                    \
					static_cast<int>(a_loc.line()),                       \
					a_loc.function_name() },                              \
				spdlog::level::a_type,                                    \
				a_fmt,                                                    \
				std::forward<Args>(a_args)...);                           \
		}                                                                 \
	};                                                                    \
                                                                          \
	template <class... Args>                                              \
	a_func(fmt::format_string<Args...>, Args&&...) -> a_func<Args...>;

namespace SKSE::log
{
	SKSE_MAKE_SOURCE_LOGGER(trace, trace);
	SKSE_MAKE_SOURCE_LOGGER(debug, debug);
	SKSE_MAKE_SOURCE_LOGGER(info, info);
	SKSE_MAKE_SOURCE_LOGGER(warn, warn);
	SKSE_MAKE_SOURCE_LOGGER(error, err);
	SKSE_MAKE_SOURCE_LOGGER(critical, critical);

	[[nodiscard]] std::optional<std::filesystem::path> log_directory();

	void add_papyrus_sink(std::regex a_filter);
	void remove_papyrus_sink();
}

#undef SKSE_MAKE_SOURCE_LOGGER
