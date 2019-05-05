#pragma once


namespace RE
{
	class hkpBroadPhaseHandle
	{
	public:
		UInt32 id;	// 0
	};
	STATIC_ASSERT(sizeof(hkpBroadPhaseHandle) == 0x4);
}
