#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAlphaCutoff : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAlphaCutoff;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAlphaCutoff;


		virtual ~ExtraAlphaCutoff();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAlphaCutoff; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		SInt8  cutoff;			// 10
		SInt8  originalCutoff;	// 11
		UInt16 pad12;			// 12
		UInt32 pad14;			// 14
	};
	STATIC_ASSERT(sizeof(ExtraAlphaCutoff) == 0x18);
}
