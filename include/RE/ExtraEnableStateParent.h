#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraEnableStateParent : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEnableStateParent;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEnableStateParent;


		virtual ~ExtraEnableStateParent();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kEnableStateParent; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk14 != a_rhs->unk14 || unk10 != a_rhs->unk10; }


		// members
		SInt8			flags;	 // 10
		UInt8			pad11;	 // 11
		UInt16			pad12;	 // 12
		ObjectRefHandle parent;	 // 14
	};
	STATIC_ASSERT(sizeof(ExtraEnableStateParent) == 0x18);
}
