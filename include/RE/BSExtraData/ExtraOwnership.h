#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESForm;


	class ExtraOwnership : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOwnership;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOwnership;


		ExtraOwnership();
		explicit ExtraOwnership(TESForm* a_owner);
		virtual ~ExtraOwnership() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kOwnership; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return owner != a_rhs->owner; }


		// members
		TESForm* owner;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraOwnership) == 0x18);
}
