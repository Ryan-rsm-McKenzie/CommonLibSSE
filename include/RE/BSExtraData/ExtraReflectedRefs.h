#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


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
