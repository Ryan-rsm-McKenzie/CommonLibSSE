#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class ExtraDistantData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraDistantData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kDistantData;


		virtual ~ExtraDistantData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kDistantData; }


		// members
		NiPoint3 landNormal;  // 10
		UInt32	 pad1C;		  // 1C
	};
	STATIC_ASSERT(sizeof(ExtraDistantData) == 0x20);
}
