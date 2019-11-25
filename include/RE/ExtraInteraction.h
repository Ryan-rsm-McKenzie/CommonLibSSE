#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraInteraction : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraInteraction;


		enum { kExtraTypeID = ExtraDataType::kInteraction };


		virtual ~ExtraInteraction();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { reutrn kInteraction; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraInteraction) == 0x18);
}
