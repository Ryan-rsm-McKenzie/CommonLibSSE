#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiPoint3.h"


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
		NiPoint3	  landNormal;  // 10
		std::uint32_t pad1C;	   // 1C
	};
	static_assert(sizeof(ExtraDistantData) == 0x20);
}
