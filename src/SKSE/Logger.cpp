#include "SKSE/Logger.h"

#include <debugapi.h>  // OutputDebugStringA
#include <objbase.h>  // CoTaskMemFree

#include <cstdarg>  // va_list, va_start, va_copy, va_end
#include <cstdio>  // snprintf, vsnprintf
#include <cwchar>  // wcslen
#include <memory>  // unique_ptr
#include <sstream>  // ostringstream
#include <vector>  // vector


namespace SKSE
{
	bool Logger::OpenRelative(REFKNOWNFOLDERID a_referenceID, const wchar_t* a_fileName, std::ios_base::openmode a_mode)
	{
		wchar_t* pathBuffer;
		auto result = SHGetKnownFolderPath(a_referenceID, KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, NULL, &pathBuffer);
		std::unique_ptr<wchar_t[], decltype(&CoTaskMemFree)> path(pathBuffer, CoTaskMemFree);
		if (result != S_OK) {
			return false;
		}

		std::size_t prefixLen = std::wcslen(path.get());
		std::size_t postfixLen = std::wcslen(a_fileName);
		std::vector<wchar_t> fullPath(prefixLen + postfixLen + 1);
		for (std::size_t i = 0; i < prefixLen; ++i) {
			fullPath[i] = path[i];
		}
		for (std::size_t i = 0; i < postfixLen; ++i) {
			fullPath[prefixLen + i] = a_fileName[i];
		}
		fullPath[prefixLen + postfixLen] = L'\0';

		_file.open(path.get(), a_mode);
		return _file.is_open();
	}


	bool Logger::OpenAbsolute(const char* a_fileName, std::ios_base::openmode a_mode)
	{
		_file.open(a_fileName, a_mode);
		return _file.is_open();
	}


	bool Logger::OpenAbsolute(const wchar_t* a_fileName, std::ios_base::openmode a_mode)
	{
		_file.open(a_fileName, a_mode);
		return _file.is_open();
	}


	void Logger::SetPrintLevel(Level a_printLevel)
	{
		_printLevel = a_printLevel;
	}


	void Logger::SetFlushLevel(Level a_flushLevel)
	{
		_flushLevel = a_flushLevel;
	}


	void Logger::Print(Level a_level, const char* a_string)
	{
		if (a_level >= _printLevel) {
			Print_Impl(a_level, a_string);
		}
	}


	void Logger::VPrint(Level a_level, const char* a_format, ...)
	{
		if (a_level < _printLevel) {
			return;
		}

		std::va_list args1;
		va_start(args1, a_format);
		std::va_list args2;
		va_copy(args2, args1);

		std::vector<char> buf(std::snprintf(0, 0, a_format, args1) + 1);
		va_end(args1);
		std::snprintf(buf.data(), buf.size(), a_format, args2);
		va_end(args2);

		_file << buf.data() << '\n';

		if (a_level >= _flushLevel) {
			_file.flush();
		}
	}


	void Logger::Print_Impl(Level a_level, const char* a_string)
	{
		_file << a_string << '\n';

		if (a_level >= _flushLevel) {
			_file.flush();
		}
	}


	decltype(Logger::_file) Logger::_file;
	decltype(Logger::_printLevel) Logger::_printLevel = Logger::Level::kMessage;
	decltype(Logger::_flushLevel) Logger::_flushLevel = Logger::Level::kMessage;


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
			oss << a_file << '(' << a_line << "): " << buf.data();
			Logger::Print_Impl(a_level, oss.str().c_str());

#if _DEBUG
			oss << '\n';
			OutputDebugStringA(oss.str().c_str());
#endif
		}
	}
}
