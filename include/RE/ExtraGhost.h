#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraGhost : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraGhost;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kGhost;


		virtual ~ExtraGhost();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kGhost; }


		// members
		bool   ghost;  // 10
		UInt8  pad11;  // 11
		UInt16 pad12;  // 12
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraGhost) == 0x18);
}
