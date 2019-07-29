#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraMagicLight

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraMagicLight : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMagicLight;


		enum { kExtraTypeID = ExtraDataType::kMagicLight };


		struct Data
		{
			NiPointer<NiRefObject>	unk00;	// 00
			UInt64					unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~ExtraMagicLight();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kMagicLight; }


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraMagicLight) == 0x18);
}
