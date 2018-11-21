#pragma once

#include "skse64/GameBSExtraData.h"  // BSExtraData
#include "skse64/GameTypes.h"  // tArray


namespace RE
{
	class TESFaction;


	class ExtraFactionChanges : public BSExtraData
	{
	public:
		ExtraFactionChanges();
		virtual ~ExtraFactionChanges();


		struct FactionInfo
		{
			TESFaction* faction;	// 0
			SInt8		rank;		// 8
			UInt8		pad[3];		// 9
		};


		tArray<FactionInfo>	factions;	// 10
		UInt64				unk28;		// 28
		UInt8				unk30;		// 30 - SE: this used to be at beginning in Skyrim32
		UInt8				unk31[7];	// 31
	};
}
