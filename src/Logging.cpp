#include "Logging.h"

#include "common/IDebugLog.h"  // IDebugLog

#include <cstdarg>  // va_list, va_start, va_copy, va_end
#include <sstream>  // ostringstream

#include <debugapi.h>  // OutputDebugStringA
#include <stdarg.h>  // vsprintf_s
#include <stdio.h>  // vsprintf_s


namespace RE
{
	void DBOut(const char* a_file, const int a_line, IDebugLog::LogLevel a_logLevel, const char* a_fmt, ...)
	{
		static char formatBuf[8192] = { 0 };
		std::va_list args1;
		va_start(args1, a_fmt);
#if _DEBUG
		std::va_list args2;
		va_copy(args2, args1);
#endif
		std::ostringstream oss;
		oss << a_file << "(" << a_line << "): " << a_fmt;
		gLog.Log(a_logLevel, oss.str().c_str(), args1);
		va_end(args1);
#if _DEBUG
		vsprintf_s(formatBuf, sizeof(formatBuf), a_fmt, args2);
		va_end(args2);
		oss.str("");
		oss << a_file << "(" << a_line << "): " << formatBuf << "\n";
		OutputDebugStringA(oss.str().c_str());
#endif
	}
}
