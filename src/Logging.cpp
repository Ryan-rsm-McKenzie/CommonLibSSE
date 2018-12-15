#include "Logging.h"

#include "common/IDebugLog.h"  // IDebugLog

#include <Windows.h>  // OutputDebugStringA
#include <sstream>  // ostringstream


namespace RE
{
	void DBOut(const char* a_file, const int a_line, IDebugLog::LogLevel a_logLevel, const char* a_str, ...)
	{
		static char formatBuf[8192] = { 0 };
		va_list args;
		va_start(args, a_str);
		vsprintf_s(formatBuf, sizeof(formatBuf), a_str, args);
		std::ostringstream oss;
		oss << a_file << "(" << a_line << "): ";
		oss << formatBuf;
		gLog.Log(a_logLevel, oss.str().c_str(), args);
		va_end(args);
		oss << "\n";
#if _DEBUG
		OutputDebugStringA(oss.str().c_str());
#endif
	}
}
