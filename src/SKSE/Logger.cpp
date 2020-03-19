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

#include "RE/BSScript/Internal/VirtualMachine.h"
#include "SKSE/API.h"
#include "SKSE/Trampoline.h"
#include "SKSE/VArgFormatter.h"


namespace SKSE
{
	bool Logger::OpenRelative(REFKNOWNFOLDERID a_referenceID, const std::filesystem::path& a_fileName, std::ios_base::openmode a_mode)
	{
		wchar_t* pathBuffer;
		auto result = SHGetKnownFolderPath(a_referenceID, KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, nullptr, &pathBuffer);
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
				SKSE::RegisterForAPIInitEvent([]() {
					auto papyrus = SKSE::GetPapyrusInterface();
					if (papyrus) {
						papyrus->Register([](RE::BSScript::Internal::VirtualMachine* a_vm) {
							a_vm->RegisterForLogEvent(LogEventHandler::GetSingleton());
							return true;
						});
					}
				});
			}
		} else {
			if (prev) {
				SKSE::RegisterForAPIInitEvent([]() {
					auto papyrus = SKSE::GetPapyrusInterface();
					if (papyrus) {
						papyrus->Register([](RE::BSScript::Internal::VirtualMachine* a_vm) {
							a_vm->UnregisterForLogEvent(LogEventHandler::GetSingleton());
							return true;
						});
					}
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


	bool Logger::TrackTrampolineStats(bool a_enable)
	{
		const auto prev = std::move(_trackTrampolineStats);
		_trackTrampolineStats = std::move(a_enable);
		return prev;
	}


	void Logger::Print(const char* a_string)
	{
		Print_Impl("", Level::kMessage, a_string, StampType::kMessage);
	}


	void Logger::Print(Level a_level, const char* a_string)
	{
		if (a_level >= _printLevel) {
			Print_Impl("", a_level, a_string, LevelToStamp(a_level));
		}
	}


	void Logger::VPrint(const char* a_format, ...)
	{
		std::va_list args;
		va_start(args, a_format);
		VPrint_Impl("", Level::kMessage, a_format, args, StampType::kMessage);
		va_end(args);
	}


	void Logger::VPrint(Level a_level, const char* a_format, ...)
	{
		if (a_level >= _printLevel) {
			std::va_list args;
			va_start(args, a_format);
			VPrint_Impl("", a_level, a_format, args, LevelToStamp(a_level));
			va_end(args);
		}
	}


	auto Logger::LogEventHandler::GetSingleton()
		-> LogEventHandler*
	{
		static LogEventHandler singleton;
		return &singleton;
	}


	auto Logger::LogEventHandler::ProcessEvent(const RE::BSScript::LogEvent* a_event, [[maybe_unused]] RE::BSTEventSource<RE::BSScript::LogEvent>* a_eventSource)
		-> EventResult
	{
		if (a_event->errorMsg && std::regex_search(a_event->errorMsg, Logger::_papyrusLogFilter)) {
			Logger::Print_Impl("", Logger::Level::kMessage, a_event->errorMsg, Logger::StampType::kPapyrus);
		}

		return EventResult::kContinue;
	}


	auto Logger::LevelToStamp(Level a_level)
		-> StampType
	{
		return static_cast<StampType>(a_level);
	}


	const char* Logger::GetLogStamp(StampType a_type)
	{
		if (_logStamp) {
			switch (a_type) {
			case StampType::kDebugMessage:
				return "[DEBUG] ";
			case StampType::kVerboseMessage:
				return "[VERBOSE] ";
			case StampType::kMessage:
				return "[MESSAGE] ";
			case StampType::kWarning:
				return "[WARNING] ";
			case StampType::kError:
				return "[ERROR] ";
			case StampType::kFatalError:
				return "[FATAL ERROR] ";
			case StampType::kPapyrus:
				return "[PAPYRUS] ";
			case StampType::kTrampoline:
				return "[TRAMPOLINE] ";
			default:
				return "";
			}
		}

		return "";
	}


	std::string Logger::GetTimeStamp()
	{
		if (!_timeStamp) {
			return "";
		}

		auto time = std::time(nullptr);
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


	void Logger::Print_Impl(const char* a_prefix, Level a_level, const char* a_string, StampType a_type)
	{
		std::ostringstream oss;
		oss << a_prefix << GetLogStamp(a_type) << GetTimeStamp() << a_string << '\n';

		Locker locker(_lock);

		_file << oss.str().c_str();

#if _DEBUG
		OutputDebugStringA(oss.str().c_str());
#endif

		if (a_level >= _flushLevel) {
			_file.flush();
		}
	}


	void Logger::VPrint_Impl(const char* a_prefix, Level a_level, const char* a_format, std::va_list a_args, StampType a_type)
	{
		VArgFormatter fmt(a_format, a_args);
		Print_Impl(a_prefix, a_level, fmt.c_str(), a_type);
	}


	decltype(Logger::_lock) Logger::_lock;
	decltype(Logger::_file) Logger::_file;
	decltype(Logger::_papyrusLogFilter) Logger::_papyrusLogFilter(".", Logger::DF_REGEXFLAGS);
	decltype(Logger::_printLevel) Logger::_printLevel = Logger::Level::kMessage;
	decltype(Logger::_flushLevel) Logger::_flushLevel = Logger::Level::kError;
	decltype(Logger::_logStamp) Logger::_logStamp = false;
	decltype(Logger::_timeStamp) Logger::_timeStamp = false;
	decltype(Logger::_fmt24Hour) Logger::_fmt24Hour = true;
	decltype(Logger::_hookPapyrusLog) Logger::_hookPapyrusLog = false;
	decltype(Logger::_trackTrampolineStats) Logger::_trackTrampolineStats = false;


	namespace Impl
	{
		void MacroLogger::VPrint(const char* a_file, std::size_t a_line, Logger::Level a_level, const char* a_format, ...)
		{
			if (a_level < Logger::_printLevel) {
				return;
			}

			std::ostringstream oss;
			oss << a_file << '(' << a_line << "): ";

			std::va_list args;
			va_start(args, a_format);
			Logger::VPrint_Impl(oss.str().c_str(), a_level, a_format, args, Logger::LevelToStamp(a_level));
			va_end(args);
		}


		void TrampolineLogger::LogStats(const char* a_file, std::size_t a_line, const Trampoline& a_trampoline)
		{
			if (!Logger::_trackTrampolineStats) {
				return;
			}

			std::ostringstream prefix;
			prefix << a_file << '(' << a_line << "): ";

			auto size = a_trampoline._size;
			auto capacity = a_trampoline._capacity;
			auto& name = a_trampoline._name;

			auto pct = (static_cast<double>(size) / static_cast<double>(capacity)) * 100.0;
			VArgFormatter postfix("%s => %zuB / %zuB (%05.2f%%)", name.c_str(), size, capacity, pct);

			Logger::Print_Impl(prefix.str().c_str(), Logger::Level::kMessage, postfix.c_str(), Logger::StampType::kTrampoline);
		}
	}
}
