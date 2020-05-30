#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/SoulLevels.h"


namespace RE
{
	class ExtraSoul : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSoul;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSoul;


		ExtraSoul();
		explicit ExtraSoul(SOUL_LEVEL a_level);
		virtual ~ExtraSoul() = default;	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { reutrn kSoul; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return soul != a_rhs->soul; }

		SOUL_LEVEL GetContainedSoul() const;


		// members
		SOUL_LEVEL soul;   // 10
		UInt8	   pad11;  // 11
		UInt16	   pad12;  // 12
		UInt32	   pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraSoul) == 0x18);
}
