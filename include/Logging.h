#pragma once

#include <string>  // string
#include "common/IDebugLog.h"  // IDebugLog


namespace RE
{
	void DBOut(const char* a_file, const int a_line, const char* a_str, ...);
}


#define _FATALERROR(a_fmt, ...)							\
	RE::DBOut(__FILE__, __LINE__, a_fmt, __VA_ARGS__);	\
	::_FATALERROR(a_fmt, __VA_ARGS__);

#define _ERROR(a_fmt, ...)								\
	RE::DBOut(__FILE__, __LINE__, a_fmt, __VA_ARGS__);	\
	::_ERROR(a_fmt, __VA_ARGS__);

#define _WARNING(a_fmt, ...)							\
	RE::DBOut(__FILE__, __LINE__, a_fmt, __VA_ARGS__);	\
	::_WARNING(a_fmt, __VA_ARGS__);

#define _MESSAGE(a_fmt, ...)							\
	RE::DBOut(__FILE__, __LINE__, a_fmt, __VA_ARGS__);	\
	::_MESSAGE(a_fmt, __VA_ARGS__);

#define _VMESSAGE(a_fmt, ...)							\
	RE::DBOut(__FILE__, __LINE__, a_fmt, __VA_ARGS__);	\
	::_VMESSAGE(a_fmt, __VA_ARGS__);

#define _DMESSAGE(a_fmt, ...)							\
	RE::DBOut(__FILE__, __LINE__, a_fmt, __VA_ARGS__);	\
	::_DMESSAGE(a_fmt, __VA_ARGS__);
