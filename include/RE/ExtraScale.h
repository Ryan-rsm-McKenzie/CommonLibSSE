#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraScale : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraScale;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kScale;


		virtual ~ExtraScale();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kScale; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return scale != a_rhs->scale; }


		// members
		float  scale;  // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraScale) == 0x18);
}
