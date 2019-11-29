#include "RE/GFxLog.h"

#include <cstdarg>
#include <cstdio>
#include <vector>


namespace RE
{
	GFxLog::~GFxLog()
	{}


	void GFxLog::LogMessageVarg(LogMessageType a_messageType, const char* a_fmt, va_list a_argList)
	{
		va_list args;
		va_copy(args, a_argList);
		std::vector<char> buf(std::vsnprintf(0, 0, a_fmt, a_argList) + 1);
		std::vsnprintf(buf.data(), buf.size(), a_fmt, args);
		va_end(args);
		OutputDebugString(buf.data());
	}


	void GFxLog::LogMessageByType(LogMessageType a_messageType, const char* a_fmt, ...)
	{
		va_list args;
		va_start(args, a_fmt);
		LogMessageVarg(a_messageType, a_fmt, args);
		va_end(args);
	}
}
