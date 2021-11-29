#include "RE/N/NiSystem.h"

namespace RE
{
	int NiMemcpy(void* a_dest, std::size_t a_destSize, const void* a_src, std::size_t a_count)
	{
		auto result = memcpy_s(a_dest, a_destSize, a_src, a_count);
		assert(result == 0);
		return result;
	}

	int NiSprintf(char* a_dest, std::size_t a_destSize, const char* a_format, ...)
	{
		assert(a_format);

		std::va_list kArgs;
		va_start(kArgs, a_format);
		auto ret = NiVsprintf(a_dest, a_destSize, a_format, kArgs);
		va_end(kArgs);

		return ret;
	}

	char* NiStrcat(char* a_dest, std::size_t a_destSize, const char* a_src)
	{
		strcat_s(a_dest, a_destSize, a_src);
		return a_dest;
	}

	char* NiStrncpy(char* a_dest, std::size_t a_destSize, const char* a_src, std::size_t a_count)
	{
		strncpy_s(a_dest, a_destSize, a_src, a_count);
		return a_dest;
	}

	int NiVsnprintf(char* a_dest, std::size_t a_destSize, std::size_t a_count, const char* a_format, std::va_list a_args)
	{
		if (a_destSize == 0) {
			return 0;
		}

		assert(a_dest);
		assert(a_count < a_destSize || a_count == NI_TRUNCATE);
		assert(a_format);

		a_dest[0] = '\0';

		bool truncate = (a_count == NI_TRUNCATE);

		auto result = vsnprintf_s(a_dest, a_destSize, a_count, a_format, a_args);

		if (result < -1 && !truncate) {
			result = static_cast<int>(a_count);
		}

		return result;
	}

	int NiVsprintf(char* a_dest, std::size_t a_destSize, const char* a_format, std::va_list a_args)
	{
		return NiVsnprintf(a_dest, a_destSize, NI_TRUNCATE, a_format, a_args);
	}
}
