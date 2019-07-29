#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPrimitive

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPrimitive : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPrimitive;


		enum { kExtraTypeID = ExtraDataType::kPrimitive };


		virtual ~ExtraPrimitive();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kPrimitive; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPrimitive) == 0x18);
}
