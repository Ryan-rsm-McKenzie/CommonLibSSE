#pragma once


namespace RE
{
	class TESObjectREFR;


	struct TESCombatEvent
	{
	public:
		TESObjectREFR*	source;	// 00
		TESObjectREFR*	target;	// 08
		UInt32			state;	// 10
		UInt32			pad14;	// 14
	};
	STATIC_ASSERT(sizeof(TESCombatEvent) == 0x18);
}
