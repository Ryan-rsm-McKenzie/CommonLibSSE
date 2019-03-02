#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraFlags : public BSExtraData
	{
	public:
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
