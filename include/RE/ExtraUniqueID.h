#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraUniqueID : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kUniqueID };


		virtual ~ExtraUniqueID();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kUniqueID; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt32	ownerFormID;	// 10
		UInt32	uniqueID;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraUniqueID) == 0x18);
}
