#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESGrabReleaseEvent
	{
		NiPointer<TESObjectREFR>	grabbedObj;	// 00
		bool						unk08;		// 08
		UInt8						pad09;		// 09
		UInt16						pad0A;		// 09
		UInt32						pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(TESGrabReleaseEvent) == 0x10);
}
