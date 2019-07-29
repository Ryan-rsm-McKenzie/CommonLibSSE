#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEnableStateParent

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraEnableStateParent : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEnableStateParent;


		enum { kExtraTypeID = ExtraDataType::kEnableStateParent };


		virtual ~ExtraEnableStateParent();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEnableStateParent; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk14 != a_rhs->unk14 || unk10 != a_rhs->unk10; }


		// members
		UInt8	unk10;	// 10
		UInt8	pad11;	// 11
		UInt16	pad12;	// 12
		UInt32	unk14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraEnableStateParent) == 0x18);
}
