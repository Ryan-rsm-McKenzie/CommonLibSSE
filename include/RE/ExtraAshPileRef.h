#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraAshPileRef : public BSExtraData
	{
	public:
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
