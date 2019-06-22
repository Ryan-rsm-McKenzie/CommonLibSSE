#pragma once

#include <KnownFolders.h>
#include <ShlObj.h>  // REFKNOWNFOLDERID

#include <fstream>  // ofstream
#include <ios>  // ios_base


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


		static constexpr std::ios_base::openmode DEFAULT_OPENMODE = std::ios_base::out | std::ios_base::trunc;


		static bool OpenRelative(REFKNOWNFOLDERID a_referenceID, const wchar_t* a_fileName, std::ios_base::openmode a_mode = DEFAULT_OPENMODE);
		static bool OpenAbsolute(const char* a_fileName, std::ios_base::openmode a_mode = DEFAULT_OPENMODE);
		static bool OpenAbsolute(const wchar_t* a_fileName, std::ios_base::openmode a_mode = DEFAULT_OPENMODE);

		static void SetPrintLevel(Level a_printLevel);
		static void SetFlushLevel(Level a_flushLevel);

		static void Print(Level a_level, const char* a_string);
		static void VPrint(Level a_level, const char* a_format, ...);

	private:
		friend class Impl::ConsoleLogger;


		Logger() = delete;
		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		~Logger() = delete;

		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;

		static void Print_Impl(Level a_level, const char* a_string);


		static std::ofstream _file;
		static Level _printLevel;
		static Level _flushLevel;
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
