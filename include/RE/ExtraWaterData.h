#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWaterData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/hkRefPtr.h"  // hkRefPtr


namespace RE
{
	class hkReferencedObject;


	class ExtraWaterData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWaterData;


		enum { kExtraTypeID = ExtraDataType::kWaterData };


		struct Data
		{
			void*	unk00;	// 00
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
		};
		STATIC_ASSERT(sizeof(Data) == 0x18);


		virtual ~ExtraWaterData();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kWaterData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64							unk10;	// 10
		hkRefPtr<hkReferencedObject>	unk18;	// 18
		Data*							unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraWaterData) == 0x28);
}
