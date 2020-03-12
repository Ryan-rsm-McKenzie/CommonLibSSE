#pragma once


namespace RE
{
	struct GArrayDefaultPolicy
	{
	public:
		// members
		UPInt capacity;	 // 0
	};
	STATIC_ASSERT(sizeof(GArrayDefaultPolicy) == 0x8);
}
