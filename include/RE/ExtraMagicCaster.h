#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraMagicCaster

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/MagicCaster.h"  // MagicCaster


namespace RE
{
	class ExtraMagicCaster :
		public BSExtraData,	// 00
		public MagicCaster	// 10
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMagicCaster;


		enum { kExtraTypeID = ExtraDataType::kMagicCaster };


		virtual ~ExtraMagicCaster();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kMagicCaster; }
	};
	STATIC_ASSERT(sizeof(ExtraMagicCaster) == 0x58);
}
