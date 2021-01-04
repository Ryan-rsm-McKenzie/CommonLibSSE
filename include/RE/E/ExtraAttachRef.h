#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"

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
		std::uint32_t	pad14;		// 14
	};
	static_assert(sizeof(ExtraAttachRef) == 0x18);
}
