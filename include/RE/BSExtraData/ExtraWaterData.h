#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/hkRefPtr.h"


namespace RE
{
	namespace BSCurrent
	{
		struct ActionArray
		{
			__m128* buffer;			// 00
			UInt32	bufferSize;		// 08
			UInt32	effectiveSize;	// 0C
			UInt32	count;			// 10
			UInt32	pad14;			// 14
		};
		STATIC_ASSERT(sizeof(ActionArray) == 0x18);
	}


	class hkReferencedObject;


	class ExtraWaterData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWaterData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kWaterData;


		virtual ~ExtraWaterData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kWaterData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64						 unk10;			// 10
		hkRefPtr<hkReferencedObject> unk18;			// 18
		BSCurrent::ActionArray*		 currentArray;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraWaterData) == 0x28);
}
