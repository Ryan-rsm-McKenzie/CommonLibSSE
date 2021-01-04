#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/E/ExtraDataTypes.h"

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
	static_assert(sizeof(ExtraReflectorRefs) == 0x28);
}
