#pragma once


namespace RE
{
	class TESFaction;


	struct FACTION_RANK	 // SNAM
	{
	public:
		// members
		TESFaction* faction;  // 00
		SInt8		rank;	  // 08
		UInt8		pad09;	  // 09
		UInt16		pad0A;	  // 0A
		UInt32		pad0C;	  // 0C
	};
	STATIC_ASSERT(sizeof(FACTION_RANK) == 0x10);
}
