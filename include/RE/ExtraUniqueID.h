#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraUniqueID : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kUniqueID };


		ExtraUniqueID();
		ExtraUniqueID(FormID a_owner, UInt16 a_uniqueID);
		virtual ~ExtraUniqueID();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kUniqueID; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return uniqueID != a_rhs->uniqueID || owner != a_rhs->owner; }


		// members
		FormID	owner;		// 10
		UInt16	uniqueID;	// 14
		UInt16	pad16;		// 16
	};
	STATIC_ASSERT(sizeof(ExtraUniqueID) == 0x18);
}
