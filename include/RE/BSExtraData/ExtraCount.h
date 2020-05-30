#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCount : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCount;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCount;


		ExtraCount();
		explicit ExtraCount(SInt16 a_count);
		virtual ~ExtraCount() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCount; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return return count != a_rhs->count; }


		// members
		SInt16 count;  // 10
		UInt16 pad12;  // 12
		SInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraCount) == 0x18);
}
