#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSSoundHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraActivateLoopSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraActivateLoopSound;


		enum { kExtraTypeID = ExtraDataType::kActivateLoopSound };


		virtual ~ExtraActivateLoopSound();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kActivateLoopSound; }


		// members
		BSSoundHandle	handle;	// 10
		UInt32			pad1C;	// 1C
	};
	STATIC_ASSERT(sizeof(ExtraActivateLoopSound) == 0x20);
}
