#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLinkedRef

#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class BGSKeyword;
	class TESObjectREFR;


	class ExtraLinkedRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLinkedRef;


		enum { kExtraTypeID = ExtraDataType::kLinkedRef };


		struct Entry
		{
			BGSKeyword*		keyword;	// 00
			TESObjectREFR*	linkedRef;	// 08
		};
		STATIC_ASSERT(sizeof(Entry) == 0x10);


		virtual ~ExtraLinkedRef();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLinkedRef; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTSmallArray<Entry> entries;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLinkedRef) == 0x30);
}
