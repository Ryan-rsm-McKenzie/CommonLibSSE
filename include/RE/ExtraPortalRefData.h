#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct PortalLinkedRefData
	{
		ObjectRefHandle linkedRefs[2];	// 0
	};
	STATIC_ASSERT(sizeof(PortalLinkedRefData) == 0x8);


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
	STATIC_ASSERT(sizeof(ExtraPortalRefData) == 0x18);
}
