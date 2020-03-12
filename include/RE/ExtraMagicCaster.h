#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/MagicCaster.h"


namespace RE
{
	class ExtraMagicCaster :
		public BSExtraData,	 // 00
		public MagicCaster	 // 10
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMagicCaster;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMagicCaster;


		virtual ~ExtraMagicCaster();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kMagicCaster; }
	};
	STATIC_ASSERT(sizeof(ExtraMagicCaster) == 0x58);
}
