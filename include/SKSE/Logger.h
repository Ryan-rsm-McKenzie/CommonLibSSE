#pragma once

#include <KnownFolders.h>
#include <ShlObj.h>  // REFKNOWNFOLDERID

#include <cstdarg>  // va_list
#include <filesystem> // path
#include <fstream>  // ofstream
#include <ios>  // ios_base
#include <regex>  // regex
#include <string>  // string
#include <utility>  // pair

#include "RE/BSScript/LogEvent.h"  // BSScript::LogEvent
#include "RE/BSTEvent.h"  // BSTEventSink


namespace SKSE
{
	namespace Impl
	{
		class ConsoleLogger;
	}


	class Logger
	{
	public:
		enum class Level
		{
			kDebugMessage,
			kVerboseMessage,
			kMessage,
			kWarning,
			kError,
			kFatalError
		};


		static constexpr auto DF_OPENMODE = std::ios_base::out | std::ios_base::trunc;
		static constexpr auto DF_REGEXFLAGS = std::regex::grep | std::regex::icase;


		static bool OpenRelative(REFKNOWNFOLDERID a_referenceID, const std::filesystem::path& a_fileName, std::ios_base::openmode a_mode = DF_OPENMODE);
		static bool OpenRelative(REFKNOWNFOLDERID a_referenceID, std::filesystem::path&& a_fileName, std::ios_base::openmode a_mode = DF_OPENMODE);
		static bool OpenAbsolute(const std::filesystem::path& a_fileName, std::ios_base::openmode a_mode = DF_OPENMODE);
		static bool OpenAbsolute(std::filesystem::path&& a_fileName, std::ios_base::openmode a_mode = DF_OPENMODE);

		static Level SetPrintLevel(Level a_printLevel);
		static Level SetFlushLevel(Level a_flushLevel);
		static bool UseLogStamp(bool a_enable);
		static std::pair<bool, bool> UseTimeStamp(bool a_enable, bool a_fmt24Hour = true);
		static bool HookPapyrusLog(bool a_enable);
		static std::regex SetPapyrusLogFilter(std::string a_filter, std::regex::flag_type a_flags = DF_REGEXFLAGS);
		static std::regex SetPapyrusLogFilter(std::regex a_filter);

		static void Print(const char* a_string);
		static void Print(Level a_level, const char* a_string);
		static void VPrint(const char* a_format, ...);
		static void VPrint(Level a_level, const char* a_format, ...);

	private:
		friend class Impl::ConsoleLogger;
		friend class LogEventHandler;


		class LogEventHandler : public RE::BSTEventSink<RE::BSScript::LogEvent>
		{
		public:
			static LogEventHandler* GetSingleton();

			virtual	RE::EventResult ReceiveEvent(RE::BSScript::LogEvent* a_event, RE::BSTEventSource<RE::BSScript::LogEvent>* a_eventSource) override;

		private:
			LogEventHandler() = default;
			LogEventHandler(const LogEventHandler&) = delete;
			LogEventHandler(LogEventHandler&&) = delete;
			virtual ~LogEventHandler() = default;

			LogEventHandler& operator=(const LogEventHandler&) = delete;
			LogEventHandler& operator=(LogEventHandler&&) = delete;
		};


		Logger() = delete;
		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		~Logger() = delete;

		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;

		static const char* GetLogStamp(Level a_level);
		static std::string GetTimeStamp();
		static void Print_Impl(Level a_level, const char* a_string);
		static void VPrint_Impl(Level a_level, const char* a_format, std::va_list a_args);


		static std::ofstream _file;
		static std::regex _papyrusLogFilter;
		static Level _printLevel;
		static Level _flushLevel;
		static bool _logStamp;
		static bool _timeStamp;
		static bool _fmt24Hour;
		static bool _hookPapyrusLog;
	};


	namespace Impl
	{
		class ConsoleLogger
		{
		public:
			static void VPrint(const char* a_file, const std::size_t a_line, Logger::Level a_level, const char* a_format, ...);

		private:
			ConsoleLogger() = delete;
			ConsoleLogger(const ConsoleLogger&) = delete;
			ConsoleLogger(ConsoleLogger&&) = delete;
			~ConsoleLogger() = delete;

			ConsoleLogger& operator=(const ConsoleLogger&) = delete;
			ConsoleLogger& operator=(ConsoleLogger&&) = delete;
		};
	}
}


#define _DMESSAGE(a_fmt, ...)	SKSE::Impl::ConsoleLogger::VPrint(__FILE__, __LINE__, SKSE::Logger::Level::kDebugMessage, a_fmt, __VA_ARGS__)
#define _VMESSAGE(a_fmt, ...)	SKSE::Impl::ConsoleLogger::VPrint(__FILE__, __LINE__, SKSE::Logger::Level::kVerboseMessage, a_fmt, __VA_ARGS__)
#define _MESSAGE(a_fmt, ...)	SKSE::Impl::ConsoleLogger::VPrint(__FILE__, __LINE__, SKSE::Logger::Level::kMessage, a_fmt, __VA_ARGS__)
#define _WARNING(a_fmt, ...)	SKSE::Impl::ConsoleLogger::VPrint(__FILE__, __LINE__, SKSE::Logger::Level::kWarning, a_fmt, __VA_ARGS__)
#define _ERROR(a_fmt, ...)		SKSE::Impl::ConsoleLogger::VPrint(__FILE__, __LINE__, SKSE::Logger::Level::kError, a_fmt, __VA_ARGS__)
#define _FATALERROR(a_fmt, ...)	SKSE::Impl::ConsoleLogger::VPrint(__FILE__, __LINE__, SKSE::Logger::Level::kFatalError, a_fmt, __VA_ARGS__)
