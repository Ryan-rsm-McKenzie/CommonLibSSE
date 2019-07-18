#pragma once


namespace RE
{
	struct TESInitScriptEvent
	{
		TESObjectREFR* objRef;	// 0
	};
	STATIC_ASSERT(sizeof(TESInitScriptEvent) == 0x8);
}
