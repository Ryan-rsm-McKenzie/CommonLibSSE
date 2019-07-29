#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAttachedArrows3D

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAttachedArrows3D : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAttachedArrows3D;


		enum { kExtraTypeID = ExtraDataType::kAttachedArrows3D };


		virtual ~ExtraAttachedArrows3D();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kAttachedArrows3D; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
	};
	STATIC_ASSERT(sizeof(ExtraAttachedArrows3D) == 0x30);
}
