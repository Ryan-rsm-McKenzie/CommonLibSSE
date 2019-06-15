#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraStartingPosition

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // BGSLocation


namespace RE
{
	class ExtraStartingPosition : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraStartingPosition;


		enum { kExtraTypeID = ExtraDataType::kStartingPosition };


		virtual ~ExtraStartingPosition();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kStartingPosition; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk28 != a_rhs->unk28 || unk10 != a_rhs->unk10 || unk20 != a_rhs->unk20; }


		// members
		float			unk10;	// 10
		float			unk14;	// 14
		float			unk18;	// 18
		UInt32			unk1C;	// 1C
		UInt64			unk20;	// 20
		BGSLocation*	unk28;	// 28
	};
	STATIC_ASSERT(sizeof(ExtraStartingPosition) == 0x30);
}
