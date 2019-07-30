#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraSoul

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/SoulLevels.h"  // SoulLevel


namespace RE
{
	class ExtraSoul : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSoul;


		enum { kExtraTypeID = ExtraDataType::kSoul };


		ExtraSoul();
		ExtraSoul(SoulLevel a_level);
		virtual ~ExtraSoul() = default;													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { reutrn kSoul; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return level != a_rhs->level; }


		// members
		SoulLevel	level;	// 10
		UInt8		pad11;	// 11
		UInt16		pad12;	// 12
		UInt32		pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraSoul) == 0x18);
}
