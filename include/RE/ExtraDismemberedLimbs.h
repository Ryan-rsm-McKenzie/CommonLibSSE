#pragma once

#include "RE/BGSBodyPartDefs.h"
#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESForm;


	struct DismemberedLimb
	{
		BSTArray<TESForm*>			 objects;  // 00
		BGSBodyPartDefs::LIMB_ENUM_8 limb;	   // 18
		bool						 unk19;	   // 19
		bool						 unk1A;	   // 1A
		UInt8						 pad1B;	   // 1B
		UInt32						 pad1C;	   // 1C
	};
	STATIC_ASSERT(sizeof(DismemberedLimb) == 0x20);


	class ExtraDismemberedLimbs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraDismemberedLimbs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kDismemberedLimbs;


		virtual ~ExtraDismemberedLimbs();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kDismemberedLimbs; }


		// members
		UInt16					   limbs;			  // 10
		bool					   eaten;			  // 12
		UInt8					   unk13;			  // 13
		UInt32					   unk14;			  // 14
		TESForm*				   deathObject;		  // 18
		BSTArray<DismemberedLimb*> dismemberedLimbs;  // 20
		BGSBodyPartDefs::LIMB_ENUM lastHitLimb;		  // 38
		UInt32					   pad3C;			  // 3C
	};
	STATIC_ASSERT(sizeof(ExtraDismemberedLimbs) == 0x40);
}
