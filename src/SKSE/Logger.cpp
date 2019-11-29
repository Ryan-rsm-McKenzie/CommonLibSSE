#include "SKSE/Logger.h"

#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <cwchar>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "RE/BSScript/Internal/VirtualMachine.h"
#include "SKSE/API.h"


namespace SKSE
{
	bool Logger::OpenRelative(REFKNOWNFOLDERID a_referenceID, const std::filesystem::path& a_fileName, std::ios_base::openmode a_mode)
	{
		wchar_t* pathBuffer;
		auto result = SHGetKnownFolderPath(a_referenceID, KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, NULL, &pathBuffer);
		std::unique_ptr<wchar_t[], decltype(&CoTaskMemFree)> path(pathBuffer, CoTaskMemFree);
		if (result != S_OK) {
			return false;
		}

		auto fileName = a_fileName.native();
		fileName.insert(0, path.get());
		std::filesystem::path filePath(std::move(fileName));
		auto parentPath = filePath.parent_path();
		std::error_code err;
		std::filesystem::create_directories(parentPath, err);
		assert(!err);

		_file.open(filePath, a_mode);
		auto isOpen = _file.is_open();
		assert(isOpen);
		return isOpen;
	}


	bool Logger::OpenRelative(REFKNOWNFOLDERID a_referenceID, std::filesystem::path&& a_fileName, std::ios_base::openmode a_mode)
	{
		return OpenRelative(a_referenceID, a_fileName, a_mode);
	}


	bool Logger::OpenAbsolute(const std::filesystem::path& a_fileName, std::ios_base::openmode a_mode)
	{
		auto parentPath = a_fileName.parent_path();
		std::error_code err;
		std::filesystem::create_directories(parentPath, err);
		assert(!err);

		_file.open(a_fileName, a_mode);
		auto isOpen = _file.is_open();
		assert(isOpen);
		return isOpen;
	}


	bool Logger::OpenAbsolute(std::filesystem::path&& a_fileName, std::ios_base::openmode a_mode)
	{
		return OpenAbsolute(a_fileName, a_mode);
	}


	auto Logger::SetPrintLevel(Level a_printLevel)
		-> Level
	{
		auto prev = std::move(_printLevel);
		_printLevel = std::move(a_printLevel);
		return prev;
	}


	auto Logger::SetFlushLevel(Level a_flushLevel)
		-> Level
	{
		auto prev = std::move(_flushLevel);
		_flushLevel = std::move(a_flushLevel);
		return prev;
	}


	bool Logger::UseLogStamp(bool a_enable)
	{
		auto prev = std::move(_logStamp);
		_logStamp = std::move(a_enable);
		return prev;
	}


	std::pair<bool, bool> Logger::UseTimeStamp(bool a_enable, bool a_fmt24Hour)
	{
		auto prev = std::make_pair(std::move(_timeStamp), std::move(_fmt24Hour));
		_timeStamp = std::move(a_enable);
		_fmt24Hour = std::move(a_fmt24Hour);
		return prev;
	}


	bool Logger::HookPapyrusLog(bool a_enable)
	{
		auto prev = std::move(_hookPapyrusLog);
		_hookPapyrusLog = std::move(a_enable);

		if (_hookPapyrusLog) {
			if (!prev) {
				SKSE::RegisterForAPIInitEvent([]()
				{
					auto papyrus = SKSE::GetPapyrusInterface();
					papyrus->Register([](RE::BSScript::Internal::VirtualMachine* a_vm)
					{
						a_vm->AddLogEventSink(LogEventHandler::GetSingleton());
						return true;
					});
				});
			}
		} else {
			if (prev) {
				SKSE::RegisterForAPIInitEvent([]()
				{
					auto papyrus = SKSE::GetPapyrusInterface();
					papyrus->Register([](RE::BSScript::Internal::VirtualMachine* a_vm)
					{
						a_vm->RemoveLogEventSink(LogEventHandler::GetSingleton());
						return true;
					});
				});
			}
		}

		return prev;
	}


	std::regex Logger::SetPapyrusLogFilter(std::string a_filter, std::regex::flag_type a_flags)
	{
		auto prev = std::move(_papyrusLogFilter);
		_papyrusLogFilter.assign(a_filter, a_flags);
		return prev;
	}


	std::regex Logger::SetPapyrusLogFilter(std::regex a_filter)
	{
		auto prev = std::move(_papyrusLogFilter);
		_papyrusLogFilter = std::move(a_filter);
		return prev;
	}


	void Logger::Print(const char* a_string)
	{
		Print_Impl(Level::kMessage, a_string);
	}


	void Logger::Print(Level a_level, const char* a_string)
	{
		if (a_level >= _printLevel) {
			Print_Impl(a_level, a_string);
		}
	}


	void Logger::VPrint(const char* a_format, ...)
	{
		std::va_list args;
		va_start(args, a_format);
		VPrint_Impl(Level::kMessage, a_format, args);
		va_end(args);
	}


	void Logger::VPrint(Level a_level, const char* a_format, ...)
	{
		if (a_level >= _printLevel) {
			std::va_list args;
			va_start(args, a_format);
			VPrint_Impl(a_level, a_format, args);
			va_end(args);
		}
	}


	auto Logger::LogEventHandler::GetSingleton()
		-> LogEventHandler*
	{
		static LogEventHandler singleton;
		return &singleton;
	}


	RE::EventResult Logger::LogEventHandler::ReceiveEvent(RE::BSScript::LogEvent* a_event, RE::BSTEventSource<RE::BSScript::LogEvent>* a_eventSource)
	{
		if (!std::regex_search(a_event->text, Logger::_papyrusLogFilter)) {
			return RE::EventResult::kContinue;
		}

		std::string msg;

		if (Logger::_logStamp) {
			msg += "[PAPYRUS] ";
		}

		if (Logger::_timeStamp) {
			msg += Logger::GetTimeStamp();
		}

		msg += a_event->text;
		msg += '\n';
		Logger::Print(msg.c_str());

#if _DEBUG
		OutputDebugStringA(msg.c_str());
#endif

		return RE::EventResult::kContinue;
	}


	const char* Logger::GetLogStamp(Level a_level)
	{
		if (_logStamp) {
			switch (a_level) {
			case Level::kDebugMessage:
				return "[DEBUG] ";
			case Level::kVerboseMessage:
				return "[VERBOSE] ";
			case Level::kMessage:
				return "[MESSAGE] ";
			case Level::kWarning:
				return "[WARNING] ";
			case Level::kError:
				return "[ERROR] ";
			case Level::kFatalError:
				return "[FATAL ERROR] ";
			}
		}

		return "";
	}


	std::string Logger::GetTimeStamp()
	{
		if (!_timeStamp) {
			return "";
		}

		auto time = std::time(0);
		std::tm localTime;
		auto err = localtime_s(&localTime, &time);
		if (err) {
			return "";
		}

		std::ostringstream buf;
		if (_fmt24Hour) {
			buf << std::put_time(&localTime, "(%F %T) ");
		} else {
			buf << std::put_time(&localTime, "(%F %I:%M:%S %p) ");
		}
		return buf.str();
	}


	void Logger::Print_Impl(Level a_level, const char* a_string)
	{
		_file << GetLogStamp(a_level) << GetTimeStamp() << a_string << '\n';

		if (a_level >= _flushLevel) {
			_file.flush();
		}
	}


	void Logger::VPrint_Impl(Level a_level, const char* a_format, std::va_list a_args)
	{
		std::va_list argsCopy;
		va_copy(argsCopy, a_args);

		std::vector<char> buf(std::vsnprintf(0, 0, a_format, a_args) + 1);
		std::vsnprintf(buf.data(), buf.size(), a_format, argsCopy);

		va_end(argsCopy);

		Print_Impl(a_level, buf.data());
	}


	decltype(Logger::_file) Logger::_file;
	decltype(Logger::_papyrusLogFilter) Logger::_papyrusLogFilter(".", Logger::DF_REGEXFLAGS);
	decltype(Logger::_printLevel) Logger::_printLevel = Logger::Level::kMessage;
	decltype(Logger::_flushLevel) Logger::_flushLevel = Logger::Level::kError;
	decltype(Logger::_logStamp) Logger::_logStamp = false;
	decltype(Logger::_timeStamp) Logger::_timeStamp = false;
	decltype(Logger::_fmt24Hour) Logger::_fmt24Hour = true;
	decltype(Logger::_hookPapyrusLog) Logger::_hookPapyrusLog = false;


	namespace Impl
	{
		void ConsoleLogger::VPrint(const char* a_file, const std::size_t a_line, Logger::Level a_level, const char* a_format, ...)
		{
			if (a_level < Logger::_printLevel) {
				return;
			}

			std::va_list args1;
			va_start(args1, a_format);
			std::va_list args2;
			va_copy(args2, args1);

			std::vector<char> buf(std::vsnprintf(0, 0, a_format, args1) + 1);
			va_end(args1);
			std::vsnprintf(buf.data(), buf.size(), a_format, args2);
			va_end(args2);

			std::ostringstream oss;
			oss << a_file << '(' << a_line << "): " << Logger::GetLogStamp(a_level) << Logger::GetTimeStamp() << buf.data() << '\n';
			Logger::_file << oss.str().c_str();

			if (a_level >= Logger::_flushLevel) {
				Logger::_file.flush();
			}

#if _DEBUG
			OutputDebugStringA(oss.str().c_str());
#endif
		}
	}
}
