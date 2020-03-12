#pragma once

#include "RE/ExtraDataTypes.h"
#include "RE/ExtraLight.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiRefObject;


	class ExtraMagicLight : public ExtraLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMagicLight;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMagicLight;


		virtual ~ExtraMagicLight();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kMagicLight; }
	};
	STATIC_ASSERT(sizeof(ExtraMagicLight) == 0x18);
}
