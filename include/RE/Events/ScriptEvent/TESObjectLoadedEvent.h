#pragma once


namespace RE
{
	struct TESObjectLoadedEvent
	{
	public:
		// members
		FormID formID;	// 0
		bool   loaded;	// 4
		UInt8  pad5;	// 5
		UInt16 pad6;	// 6
	};
	STATIC_ASSERT(sizeof(TESObjectLoadedEvent) == 0x8);
}
