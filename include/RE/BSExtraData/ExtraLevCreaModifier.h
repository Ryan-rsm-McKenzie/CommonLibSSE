#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	enum class LEV_CREA_MODIFIER : UInt32
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
		LEV_CREA_MODIFIER modifier;	 // 10
		UInt32			  pad14;	 // 14
	};
	STATIC_ASSERT(sizeof(ExtraLevCreaModifier) == 0x18);
}
