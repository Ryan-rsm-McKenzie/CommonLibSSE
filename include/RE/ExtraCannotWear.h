#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCannotWear

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraCannotWear : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCannotWear;


		enum { kExtraTypeID = ExtraDataType::kCannotWear };


		ExtraCannotWear();
		virtual ~ExtraCannotWear() = default;			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCannotWear; }
	};
	STATIC_ASSERT(sizeof(ExtraCannotWear) == 0x10);
}
