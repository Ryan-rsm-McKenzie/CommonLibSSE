#include "Logging.h"

#include <Windows.h>  // OutputDebugStringA
#include <sstream>  // ostringstream


namespace RE
{
	void DBOut(const char* a_file, const int a_line, const char* a_str, ...)
	{
		static char formatBuf[8192] = { 0 };
		va_list args = 0;
		va_start(args, a_str);
		vsprintf_s(formatBuf, sizeof(formatBuf), a_str, args);
		va_end(args);
		std::ostringstream os_;
		os_ << a_file << "(" << a_line << "): ";
		os_ << formatBuf << "\n";
		OutputDebugStringA(os_.str().c_str());
	}
}
