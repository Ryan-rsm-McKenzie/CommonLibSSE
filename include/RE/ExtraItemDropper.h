#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraItemDropper : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kItemDropper };


		virtual ~ExtraItemDropper();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kItemDropper; }


		// members
		RefHandle	refHandle;	// 10
		UInt32		pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraItemDropper) == 0x18);
}
