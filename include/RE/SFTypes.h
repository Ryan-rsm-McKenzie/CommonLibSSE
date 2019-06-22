#pragma once

#include <cstdlib>  // size_t
#include <limits>  // numeric_limits


namespace RE
{
	using UPInt = std::size_t;
	constexpr UPInt UPINT_MAX = std::numeric_limits<UPInt>::max();

	using SPInt = std::ptrdiff_t;
}
