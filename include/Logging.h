#pragma once

#include "common/IDebugLog.h"  // IDebugLog


namespace RE
{
	void DBOut(const char* a_file, const int a_line, IDebugLog::LogLevel a_logLevel, const char* a_str, ...);
}


#define _FATALERROR(a_fmt, ...)	RE::DBOut(__FILE__, __LINE__, IDebugLog::LogLevel::kLevel_FatalError, a_fmt, __VA_ARGS__)
#define _ERROR(a_fmt, ...)		RE::DBOut(__FILE__, __LINE__, IDebugLog::LogLevel::kLevel_Error, a_fmt, __VA_ARGS__)
#define _WARNING(a_fmt, ...)	RE::DBOut(__FILE__, __LINE__, IDebugLog::LogLevel::kLevel_Warning, a_fmt, __VA_ARGS__)
#define _MESSAGE(a_fmt, ...)	RE::DBOut(__FILE__, __LINE__, IDebugLog::LogLevel::kLevel_Message, a_fmt, __VA_ARGS__)
#define _VMESSAGE(a_fmt, ...)	RE::DBOut(__FILE__, __LINE__, IDebugLog::LogLevel::kLevel_VerboseMessage, a_fmt, __VA_ARGS__)
#define _DMESSAGE(a_fmt, ...)	RE::DBOut(__FILE__, __LINE__, IDebugLog::LogLevel::kLevel_DebugMessage, a_fmt, __VA_ARGS__)
