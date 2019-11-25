#pragma once


namespace RE
{
	class TESObjectREFR;


	struct TESInitScriptEvent
	{
		TESObjectREFR* objRef;	// 0
	};
	STATIC_ASSERT(sizeof(TESInitScriptEvent) == 0x8);
}
