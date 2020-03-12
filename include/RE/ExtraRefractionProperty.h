#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraRefractionProperty : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRefractionProperty;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRefractionProperty;


		virtual ~ExtraRefractionProperty();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRefractionProperty; }


		// members
		float  refractionPower;	 // 10
		UInt32 unk14;			 // 14
	};
	STATIC_ASSERT(sizeof(ExtraRefractionProperty) == 0x18);
}
