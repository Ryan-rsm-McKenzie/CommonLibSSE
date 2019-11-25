#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCellGrassData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCellGrassData;


		enum { kExtraTypeID = ExtraDataType::kCellGrassData };


		virtual ~ExtraCellGrassData();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCellGrassData; }


		// members
		BSTArray<void*>	unk10;	// 10
		void*			unk28;	// 28
	};
	STATIC_ASSERT(sizeof(ExtraCellGrassData) == 0x30);
}
