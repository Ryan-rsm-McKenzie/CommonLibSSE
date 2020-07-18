#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class TESForm;


	class ExtraLargeRefOwnerCells : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLargeRefOwnerCells;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLargeRefOwnerCells;


		virtual ~ExtraLargeRefOwnerCells();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kLargeRefOwnerCells; }


		// members
		BSTArray<TESForm*> ownerCells;	// 10
		std::uint64_t	   unk28;		// 28
	};
	static_assert(sizeof(ExtraLargeRefOwnerCells) == 0x30);
}
