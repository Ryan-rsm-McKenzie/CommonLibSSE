#pragma once

namespace RE
{
	constexpr auto NI_TRUNCATE = static_cast<std::size_t>(-1);

	int   NiMemcpy(void* a_dest, std::size_t a_destSize, const void* a_src, std::size_t a_count);
	int   NiSprintf(char* a_dest, std::size_t a_destSize, const char* a_format, ...);
	char* NiStrcat(char* a_dest, std::size_t a_destSize, const char* a_src);
	char* NiStrncpy(char* a_dest, std::size_t a_destSize, const char* a_src, std::size_t a_count);
	int   NiVsnprintf(char* a_dest, std::size_t a_destSize, std::size_t a_count, const char* a_format, std::va_list a_args);
	int   NiVsprintf(char* a_dest, std::size_t a_destSize, const char* a_format, std::va_list a_args);
}
