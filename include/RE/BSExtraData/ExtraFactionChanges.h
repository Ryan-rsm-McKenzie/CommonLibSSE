#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FactionRank.h"


namespace RE
{
	class TESFaction;


	class ExtraFactionChanges : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFactionChanges;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFactionChanges;


		virtual ~ExtraFactionChanges();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFactionChanges; }


		// members
		BSTArray<FACTION_RANK> factionChanges;		// 10
		TESFaction*			   crimeFaction;		// 28
		bool				   removeCrimeFaction;	// 30
		UInt8				   pad31;				// 31
		UInt16				   pad32;				// 32
		UInt32				   pad34;				// 34
	};
	STATIC_ASSERT(sizeof(ExtraFactionChanges) == 0x38);
}
