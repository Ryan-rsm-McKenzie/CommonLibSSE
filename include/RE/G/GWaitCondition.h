#pragma once

namespace RE
{
	class GWaitConditionImpl;

	class GWaitCondition
	{
	public:
		GWaitConditionImpl* impl;  // 00
	};
	static_assert(sizeof(GWaitCondition) == 0x8);
}
