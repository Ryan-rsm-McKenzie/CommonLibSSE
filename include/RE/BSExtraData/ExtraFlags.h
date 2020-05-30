#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraFlags : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFlags;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFlags;


		enum class Flag : UInt32
		{
			kNone = 0,
			kBlockActivate = 1 << 0,
			kBlockPlayerActivate = 1 << 1,
			kBlockLoadEvents = 1 << 2,
			kBlockActivateText = 1 << 3,
			kPlayerHasTaken = 1 << 5
		};


		virtual ~ExtraFlags();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFlags; }

		bool IsActivationBlocked() const;


		// members
		Flag   flags;  // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraFlags) == 0x18);
}
