#pragma once

#include <cstdarg>
#include <string>
#include <vector>


namespace SKSE
{
	class VArgFormatter
	{
	public:
		VArgFormatter(const char* a_format, ...);
		VArgFormatter(const char* a_format, std::va_list a_args);

		void operator()(const char* a_format, ...);
		void operator()(const char* a_format, std::va_list a_args);

		[[nodiscard]] std::string str() const;
		[[nodiscard]] const char* c_str() const;

	private:
		void DoFormat(const char* a_format, std::va_list a_args);


		std::vector<char> _buf;
	};
}
