#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct BGSDecalGroup;


	class ExtraDecalGroup : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraDecalGroup;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kDecalGroup;


		virtual ~ExtraDecalGroup();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kDecalGroup; }


		// members
		BGSDecalGroup* decalGroup;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraDecalGroup) == 0x18);
}
