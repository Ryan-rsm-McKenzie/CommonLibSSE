#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAmmo : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAmmo;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAmmo;


		virtual ~ExtraAmmo();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAmmo; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk18 != a_rhs->unk18 || unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;  // 10
		UInt32 unk18;  // 18
		UInt32 pad1C;  // 1C
	};
	STATIC_ASSERT(sizeof(ExtraAmmo) == 0x20);
}
