#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class AddCellGrassTask;
	class BSInstanceTriShape;


	struct CellGrassData
	{
		UInt64						  grassTypeKey;	  // 00
		BSFixedString				  grassModelKey;  // 08
		NiPointer<BSInstanceTriShape> triShape;		  // 10
		BSTArray<void*>				  unk18;		  // 18
		BSTArray<void*>				  unk30;		  // 30
	};
	STATIC_ASSERT(sizeof(CellGrassData) == 0x48);


	class ExtraCellGrassData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellGrassData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellGrassData;


		virtual ~ExtraCellGrassData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kCellGrassData; }


		// members
		BSTArray<CellGrassData*>	grassHandles;  // 10
		NiPointer<AddCellGrassTask> addGrassTask;  // 28
	};
	STATIC_ASSERT(sizeof(ExtraCellGrassData) == 0x30);
}
