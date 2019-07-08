#include "SKSE/Logger.h"

#include <debugapi.h>  // OutputDebugStringA
#include <objbase.h>  // CoTaskMemFree

#include <cassert>  // assert
#include <cstdarg>  // va_list, va_start, va_copy, va_end
#include <cstdio>  // snprintf, vsnprintf
#include <ctime>  // time
#include <cwchar>  // wcslen
#include <iomanip>  // put_time
#include <memory>  // unique_ptr
#include <sstream>  // ostringstream
#include <time.h>  // localtime_s
#include <vector>  // vector


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
		auto result = _printLevel;
		_printLevel = a_printLevel;
		return result;
	}


	auto Logger::SetFlushLevel(Level a_flushLevel)
		-> Level
	{
		auto result = _flushLevel;
		_flushLevel = a_flushLevel;
		return result;
	}


	bool Logger::UseLogStamp(bool a_enable)
	{
		auto result = _logStamp;
		_logStamp = a_enable;
		return result;
	}


	std::pair<bool, bool> Logger::UseTimeStamp(bool a_enable, bool a_fmt24Hour)
	{
		auto result = std::make_pair(_timeStamp, _fmt24Hour);
		_timeStamp = a_enable;
		_fmt24Hour = a_fmt24Hour;
		return result;
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


	std::string Logger::GetTimeStamp(Level a_level)
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
		_file << GetLogStamp(a_level) << GetTimeStamp(a_level) << a_string << '\n';

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
	decltype(Logger::_printLevel) Logger::_printLevel = Logger::Level::kMessage;
	decltype(Logger::_flushLevel) Logger::_flushLevel = Logger::Level::kError;
	decltype(Logger::_logStamp) Logger::_logStamp = false;
	decltype(Logger::_timeStamp) Logger::_timeStamp = false;
	decltype(Logger::_fmt24Hour) Logger::_fmt24Hour = true;


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
			oss << a_file << '(' << a_line << "): " << Logger::GetLogStamp(a_level) << Logger::GetTimeStamp(a_level) << buf.data() << '\n';
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
