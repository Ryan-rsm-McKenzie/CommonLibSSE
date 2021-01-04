#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraEnableStateParent : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEnableStateParent;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEnableStateParent;

		virtual ~ExtraEnableStateParent();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kEnableStateParent; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk14 != a_rhs->unk14 || unk10 != a_rhs->unk10; }

		// members
		std::int8_t		flags;	 // 10
		std::uint8_t	pad11;	 // 11
		std::uint16_t	pad12;	 // 12
		ObjectRefHandle parent;	 // 14
	};
	static_assert(sizeof(ExtraEnableStateParent) == 0x18);
}
