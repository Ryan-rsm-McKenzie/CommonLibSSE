#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCombatStyle : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCombatStyle;


		enum { kExtraTypeID = ExtraDataType::kCombatStyle };


		virtual ~ExtraCombatStyle();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCombatStyle; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCombatStyle) == 0x18);
}
