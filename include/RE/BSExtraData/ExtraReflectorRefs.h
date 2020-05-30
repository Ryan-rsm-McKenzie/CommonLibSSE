#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraReflectorRefs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraReflectorRefs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kReflectorRefs;


		virtual ~ExtraReflectorRefs();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kReflectorRefs; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<ObjectRefHandle> refs;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraReflectorRefs) == 0x28);
}
