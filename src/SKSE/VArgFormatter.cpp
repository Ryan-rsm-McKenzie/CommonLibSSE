#include "SKSE/VArgFormatter.h"

#include <cstdarg>
#include <cstdio>


namespace SKSE
{
	VArgFormatter::VArgFormatter(const char* a_format, ...) :
		_buf()
	{
		std::va_list args;
		va_start(args, a_format);
		DoFormat(a_format, args);
		va_end(args);
	}


	VArgFormatter::VArgFormatter(const char* a_format, std::va_list a_args) :
		_buf()
	{
		DoFormat(a_format, a_args);
	}


	void VArgFormatter::operator()(const char* a_format, ...)
	{
		std::va_list args;
		va_start(args, a_format);
		DoFormat(a_format, args);
		va_end(args);
	}


	void VArgFormatter::operator()(const char* a_format, std::va_list a_args)
	{
		DoFormat(a_format, a_args);
	}


	std::string VArgFormatter::str() const
	{
		return c_str();
	}


	const char* VArgFormatter::c_str() const
	{
		return _buf.data();
	}


	void VArgFormatter::DoFormat(const char* a_format, std::va_list a_args)
	{
		std::va_list argsCopy;
		va_copy(argsCopy, a_args);

		auto size = std::vsnprintf(nullptr, 0, a_format, a_args);
		if (size <= 0) {
			_buf.resize(1);
			_buf[0] = '\0';
			return;
		}

		_buf.resize(static_cast<std::size_t>(size) + 1);

		std::vsnprintf(_buf.data(), _buf.size(), a_format, argsCopy);

		va_end(argsCopy);
	}
}
