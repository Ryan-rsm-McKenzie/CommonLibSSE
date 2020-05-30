#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAttachRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAttachRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAttachRef;


		virtual ~ExtraAttachRef();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAttachRef; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return attachRef != a_rhs->attachRef; }


		// members
		ObjectRefHandle attachRef;	// 10
		UInt32			pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraAttachRef) == 0x18);
}
