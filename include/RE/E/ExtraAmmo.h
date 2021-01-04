#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraAmmo : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAmmo;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAmmo;

		virtual ~ExtraAmmo();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAmmo; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk18 != a_rhs->unk18 || unk10 != a_rhs->unk10; }

		// members
		std::uint64_t unk10;  // 10
		std::uint32_t unk18;  // 18
		std::uint32_t pad1C;  // 1C
	};
	static_assert(sizeof(ExtraAmmo) == 0x20);
}
