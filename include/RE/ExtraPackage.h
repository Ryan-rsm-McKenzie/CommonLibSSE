#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESPackage;


	class ExtraPackage : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPackage;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPackage;


		virtual ~ExtraPackage();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kPackage; }


		// members
		TESPackage*		unk10;			 // 10
		SInt32			index;			 // 18
		ObjectRefHandle target;			 // 1C
		bool			actionComplete;	 // 20
		bool			activated;		 // 21
		bool			doneOnce;		 // 22
		UInt8			unk23;			 // 23
		UInt32			unk24;			 // 24
	};
	STATIC_ASSERT(sizeof(ExtraPackage) == 0x28);
}
