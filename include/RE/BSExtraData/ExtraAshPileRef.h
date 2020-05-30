#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAshPileRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAshPileRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAshPileRef;


		ExtraAshPileRef();
		explicit ExtraAshPileRef(ObjectRefHandle a_ashPileRef);
		virtual ~ExtraAshPileRef() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAshPileRef; }


		// members
		ObjectRefHandle ashPileRef;	 // 10
		UInt32			pad14;		 // 14
	};
	STATIC_ASSERT(sizeof(ExtraAshPileRef) == 0x18);
}
