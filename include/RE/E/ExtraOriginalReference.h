#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"

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
		std::uint32_t	pad14;		// 14
	};
	static_assert(sizeof(ExtraOriginalReference) == 0x18);
}
