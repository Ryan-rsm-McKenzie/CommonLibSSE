#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraHealthPerc : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHealthPerc;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHealthPerc;


		virtual ~ExtraHealthPerc();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kHealthPerc; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt32 unk10;  // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraHealthPerc) == 0x18);
}
