#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/FormComponents/Components/MagicCaster.h"


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
	static_assert(sizeof(ExtraMagicCaster) == 0x58);
}
