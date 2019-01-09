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
		std::ostringstream oss;
		oss << a_file << "(" << a_line << "): " << a_str;
		gLog.Log(a_logLevel, oss.str().c_str(), args);
#if _DEBUG
		vsprintf_s(formatBuf, sizeof(formatBuf), a_str, args);
		oss.str("");
		oss << a_file << "(" << a_line << "): " << formatBuf << "\n";
		OutputDebugStringA(oss.str().c_str());
#endif
		va_end(args);
	}
}
