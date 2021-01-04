#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSExtraData.h"
#include "RE/B/BSTArray.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class BGSBaseAlias;

	struct BGSRefAliasInstanceData
	{
		TESQuest*					 quest;				 // 00
		const BGSBaseAlias*			 alias;				 // 08
		const BSTArray<TESPackage*>* instancedPackages;	 // 10
	};
	static_assert(sizeof(BGSRefAliasInstanceData) == 0x18);

	class ExtraAliasInstanceArray : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAliasInstanceArray;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAliasInstanceArray;

		ExtraAliasInstanceArray();
		virtual ~ExtraAliasInstanceArray();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAliasInstanceArray; }

		// members
		BSTArray<BGSRefAliasInstanceData*> aliases;	 // 10
		mutable BSReadWriteLock			   lock;	 // 28
	};
	static_assert(sizeof(ExtraAliasInstanceArray) == 0x30);
}
