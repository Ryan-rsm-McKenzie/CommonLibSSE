#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraMagicLight

#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/ExtraLight.h"  // ExtraLight
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraMagicLight : public ExtraLight
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMagicLight;


		enum { kExtraTypeID = ExtraDataType::kMagicLight };


		virtual ~ExtraMagicLight();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kMagicLight; }
	};
	STATIC_ASSERT(sizeof(ExtraMagicLight) == 0x18);
}
