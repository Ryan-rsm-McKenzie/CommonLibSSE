#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	struct PortalLinkedRefData
	{
		ObjectRefHandle linkedRefs[2];	// 0
	};
	static_assert(sizeof(PortalLinkedRefData) == 0x8);

	class ExtraPortalRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPortalRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPortalRefData;

		virtual ~ExtraPortalRefData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kPortalRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		PortalLinkedRefData* data;	// 10
	};
	static_assert(sizeof(ExtraPortalRefData) == 0x18);
}
