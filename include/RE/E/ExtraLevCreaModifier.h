#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	enum class LEV_CREA_MODIFIER
	{
		kEasy = 0,
		kMedium = 1,
		kHard = 2,
		kVeryHard = 3,
		kNone = 4
	};

	class ExtraLevCreaModifier : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLevCreaModifier;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLevCreaModifier;

		virtual ~ExtraLevCreaModifier();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLevCreaModifier; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return modifier != a_rhs->modifier; }

		// members
		stl::enumeration<LEV_CREA_MODIFIER, std::uint32_t> modifier;  // 10
		std::uint32_t									   pad14;	  // 14
	};
	static_assert(sizeof(ExtraLevCreaModifier) == 0x18);
}
