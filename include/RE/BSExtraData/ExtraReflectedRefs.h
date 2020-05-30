#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraReflectedRefs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraReflectedRefs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kReflectedRefs;


		virtual ~ExtraReflectedRefs();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kReflectedRefs; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<ObjectRefHandle> refs;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraReflectedRefs) == 0x28);
}
