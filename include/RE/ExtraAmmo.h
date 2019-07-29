#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAmmo

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAmmo : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAmmo;


		enum { kExtraTypeID = ExtraDataType::kAmmo };


		virtual ~ExtraAmmo();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kAmmo; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk18 != a_rhs->unk18 || unk10 != a_rhs->unk10; }


		// members
		UInt64	unk10;	// 10
		UInt32	unk18;	// 18
		UInt32	pad1C;	// 1C
	};
	STATIC_ASSERT(sizeof(ExtraAmmo) == 0x20);
}
