#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAshPileRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAshPileRef;


		enum { kExtraTypeID = ExtraDataType::kAshPileRef };


		virtual ~ExtraAshPileRef();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAshPileRef; }


		// members
		RefHandle	refHandle;	// 10
		UInt32		pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraAshPileRef) == 0x18);
}
