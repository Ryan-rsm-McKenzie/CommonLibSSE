#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAliasInstanceArray

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // TESQuest, TESPackage


namespace RE
{
	class BGSBaseAlias;


	class ExtraAliasInstanceArray : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAliasInstanceArray;


		enum { kExtraTypeID = ExtraDataType::kAliasInstanceArray };


		struct AliasInfo
		{
			TESQuest*				quest;		// 00
			BGSBaseAlias*			alias;		// 08
			BSTArray<TESPackage*>*	packages;	// 10
		};
		STATIC_ASSERT(sizeof(AliasInfo) == 0x18);


		ExtraAliasInstanceArray();
		virtual ~ExtraAliasInstanceArray();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAliasInstanceArray; }


		// members
		BSTArray<AliasInfo*>	aliasInfoArr;	// 10
		UInt32					unk28;			// 28
		UInt32					unk2C;			// 2C
	};
	STATIC_ASSERT(sizeof(ExtraAliasInstanceArray) == 0x30);
}
