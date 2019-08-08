#pragma once


namespace RE
{
	class TESObjectREFR;


	struct TESCombatEvent
	{
	public:
		enum class State : UInt32
		{
			kNotInCombat = 0,
			kInCombat = 1,
			kSearching = 2
		};


		TESObjectREFR*	source;	// 00
		TESObjectREFR*	target;	// 08
		State			state;	// 10
		UInt32			pad14;	// 14
	};
	STATIC_ASSERT(sizeof(TESCombatEvent) == 0x18);
}
