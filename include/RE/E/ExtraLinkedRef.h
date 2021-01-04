#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTArray.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSKeyword;
	class TESObjectREFR;

	class ExtraLinkedRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLinkedRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLinkedRef;

		struct LinkedRef
		{
			BGSKeyword*	   keyword;	 // 00
			TESObjectREFR* refr;	 // 08
		};
		static_assert(sizeof(LinkedRef) == 0x10);

		virtual ~ExtraLinkedRef();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLinkedRef; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		BSTSmallArray<LinkedRef> linkedRefs;  // 10
	};
	static_assert(sizeof(ExtraLinkedRef) == 0x30);
}
