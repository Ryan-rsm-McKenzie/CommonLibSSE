#pragma once

#undef min
#undef max

#include <cstdlib>  // size_t
#include <limits>  // numeric_limits


namespace RE
{
	typedef std::size_t UPInt;
	constexpr UPInt UPINT_MAX = std::numeric_limits<UPInt>::max();

	typedef std::ptrdiff_t SPInt;
}
