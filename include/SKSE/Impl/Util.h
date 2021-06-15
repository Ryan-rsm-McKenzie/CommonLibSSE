#pragma once

#pragma warning(push)
#include <boost/algorithm/string/predicate.hpp>
#pragma warning(pop)

namespace SKSE
{
	namespace stl
	{
		namespace string
		{
			[[nodiscard]] inline bool insensitive_string_compare(std::string_view a_str1, std::string_view a_str2)
			{
				return boost::icontains(a_str1, a_str2);
			}

			[[nodiscard]] inline bool insensitive_string_find(std::string_view a_str1, std::string_view a_str2)
			{
				return boost::ifind_first(a_str1, a_str2);
			}
		}

		template <typename First, typename... T>
		[[nodiscard]] bool is(First&& first, T&&... t)
		{
			return ((first == t) || ...);
		}
	}
}
