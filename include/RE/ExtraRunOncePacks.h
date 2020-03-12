#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct RunOncePackage
	{
		TESPackage* package;  // 00
		SInt8		day;	  // 08
		UInt8		pad09;	  // 09
		UInt16		pad0A;	  // 0A
		UInt32		pad0C;	  // 0C
	};
	STATIC_ASSERT(sizeof(RunOncePackage) == 0x10);


	class ExtraRunOncePacks : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRunOncePacks;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRunOncePacks;


		virtual ~ExtraRunOncePacks();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRunOncePacks; }


		// members
		BSSimpleList<RunOncePackage*>* packages;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraRunOncePacks) == 0x18);
}
