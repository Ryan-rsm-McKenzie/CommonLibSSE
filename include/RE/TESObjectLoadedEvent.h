#pragma once


namespace RE
{
	struct TESObjectLoadedEvent
	{
		FormID	formID;	// 0
		bool	loaded;	// 4
		UInt8	pad05;	// 5
		UInt16	pad06;	// 6
	};
	STATIC_ASSERT(sizeof(TESObjectLoadedEvent) == 0x8);
}
