#pragma once

#include "RE/FormComponents/Components/BGSBaseAlias/BGSBaseAlias.h"


namespace RE
{
	class TESCondition;


	class BGSLocAlias : public BGSBaseAlias
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLocAlias;
		inline static constexpr auto VMTYPEID = static_cast<VMTypeID>(141);


		virtual ~BGSLocAlias();	 // 00


		// members
		UInt64		  unk28;	   // 28
		UInt64		  unk30;	   // 30
		UInt64		  unk38;	   // 38
		UInt64		  unk40;	   // 40
		UInt64		  unk48;	   // 48
		UInt64		  unk50;	   // 50
		TESCondition* conditions;  // 58
	};
	STATIC_ASSERT(sizeof(BGSLocAlias) == 0x60);
}
