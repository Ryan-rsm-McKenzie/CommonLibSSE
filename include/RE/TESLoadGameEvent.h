#pragma once


namespace RE
{
	struct TESLoadGameEvent
	{
		enum class Flag : UInt32
		{
			kNone = 0
		};


		Flag	flags;	// 0
		UInt32	pad4;	// 4
	};
	STATIC_ASSERT(sizeof(TESLoadGameEvent) == 0x8);
}
