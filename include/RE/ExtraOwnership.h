#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraOwnership : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kOwnership };


		virtual ~ExtraOwnership();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kOwnership; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		TESForm* owner;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOwnership) == 0x18);
}
