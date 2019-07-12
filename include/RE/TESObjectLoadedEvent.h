#pragma once


namespace RE
{
	struct TESObjectLoadedEvent
	{
		enum class Type : UInt8
		{
			kUnloaded = 0,
			kLoaded = 1,
		};


		RE::FormID	formID;	// 0
		Type		type;	// 4 - This might be isDestroyed
		UInt8		pad05;	// 5
		UInt16		pad06;	// 6
	};
	STATIC_ASSERT(sizeof(TESObjectLoadedEvent) == 0x8);
}
