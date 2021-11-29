#pragma once

namespace RE
{
	struct GArrayDefaultPolicy
	{
	public:
		// members
		UPInt capacity;  // 0
	};
	static_assert(sizeof(GArrayDefaultPolicy) == 0x8);
}
