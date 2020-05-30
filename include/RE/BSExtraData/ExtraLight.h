#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiLight;


	struct REFR_LIGHT
	{
		NiPointer<NiLight> light;		// 00
		float			   wantDimmer;	// 08
		UInt32			   pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(REFR_LIGHT) == 0x10);


	class ExtraLight : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLight;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLight;


		virtual ~ExtraLight();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kLight; }


		// members
		REFR_LIGHT* lightData;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLight) == 0x18);
}
