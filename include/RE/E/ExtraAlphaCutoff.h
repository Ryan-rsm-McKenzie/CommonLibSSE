#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraAlphaCutoff : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAlphaCutoff;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAlphaCutoff;

		virtual ~ExtraAlphaCutoff();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAlphaCutoff; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }

		// members
		std::int8_t	  cutoff;		   // 10
		std::int8_t	  originalCutoff;  // 11
		std::uint16_t pad12;		   // 12
		std::uint32_t pad14;		   // 14
	};
	static_assert(sizeof(ExtraAlphaCutoff) == 0x18);
}
