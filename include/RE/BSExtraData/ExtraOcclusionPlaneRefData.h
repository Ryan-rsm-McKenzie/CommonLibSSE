#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct OcclusionPlaneLinkedRefData
	{
		ObjectRefHandle linkedRefs[4];	// 00
	};
	STATIC_ASSERT(sizeof(OcclusionPlaneLinkedRefData) == 0x10);


	class ExtraOcclusionPlaneRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOcclusionPlaneRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOcclusionPlaneRefData;


		virtual ~ExtraOcclusionPlaneRefData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kOcclusionPlaneRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		OcclusionPlaneLinkedRefData* data;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOcclusionPlaneRefData) == 0x18);
}
