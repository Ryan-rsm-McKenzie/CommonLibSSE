#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraUniqueID : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraUniqueID;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kUniqueID;

		ExtraUniqueID();
		ExtraUniqueID(FormID a_baseID, std::uint16_t a_uniqueID);
		virtual ~ExtraUniqueID() = default;	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kUniqueID; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return uniqueID != a_rhs->uniqueID || baseID != a_rhs->baseID; }

		// members
		FormID		  baseID;	 // 10
		std::uint16_t uniqueID;	 // 14
		std::uint16_t pad16;	 // 16
	};
	static_assert(sizeof(ExtraUniqueID) == 0x18);
}
