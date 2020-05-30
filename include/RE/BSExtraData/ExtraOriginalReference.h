#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraOriginalReference : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOriginalReference;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOriginalReference;


		virtual ~ExtraOriginalReference();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kOriginalReference; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return reference != a_rhs->reference; }


		// members
		ObjectRefHandle reference;	// 10
		UInt32			pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraOriginalReference) == 0x18);
}
