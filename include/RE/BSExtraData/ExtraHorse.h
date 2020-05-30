#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraHorse : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHorse;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHorse;


		virtual ~ExtraHorse();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kHorse; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return horseRef != a_rhs->horseRef; }


		// members
		ObjectRefHandle horseRef;  // 10
		UInt32			pad14;	   // 14
	};
	STATIC_ASSERT(sizeof(ExtraHorse) == 0x18);
}
