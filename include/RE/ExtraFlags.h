#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraFlags

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraFlags : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFlags;


		enum { kExtraTypeID = ExtraDataType::kFlags };


		enum class Flag : UInt32
		{
			kNone = 0,
			kActivationBlocked = 1 << 0
		};


		virtual ~ExtraFlags();								// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;	// 01 - { return kFlags; }

		bool					IsActivationBlocked() const;


		// members
		Flag	flags;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraFlags) == 0x18);
}
