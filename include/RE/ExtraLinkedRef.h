#pragma once

#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/BSExtraData.h"


namespace RE
{
	class BGSKeyword;
	class TESObjectREFR;


	class ExtraLinkedRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLinkedRef;


		enum { kExtraTypeID = ExtraDataType::kLinkedRef };


		struct LinkedRef
		{
			BGSKeyword*		keyword;	// 00
			TESObjectREFR*	refr;		// 08
		};
		STATIC_ASSERT(sizeof(LinkedRef) == 0x10);


		virtual ~ExtraLinkedRef();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLinkedRef; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTSmallArray<LinkedRef> linkedRefs;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLinkedRef) == 0x30);
}
