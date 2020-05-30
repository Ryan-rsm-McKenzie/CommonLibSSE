#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraUniqueID : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraUniqueID;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kUniqueID;


		ExtraUniqueID();
		ExtraUniqueID(FormID a_baseID, UInt16 a_uniqueID);
		virtual ~ExtraUniqueID() = default;	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kUniqueID; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return uniqueID != a_rhs->uniqueID || baseID != a_rhs->baseID; }


		// members
		FormID baseID;	  // 10
		UInt16 uniqueID;  // 14
		UInt16 pad16;	  // 16
	};
	STATIC_ASSERT(sizeof(ExtraUniqueID) == 0x18);
}
