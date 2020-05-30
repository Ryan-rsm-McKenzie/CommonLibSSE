#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraHasNoRumors : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHasNoRumors;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHasNoRumors;


		virtual ~ExtraHasNoRumors();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kHasNoRumors; }


		// members
		bool   noRumors;  // 10
		UInt8  pad11;	  // 11
		UInt16 pad12;	  // 12
		UInt32 pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(ExtraHasNoRumors) == 0x18);
}
