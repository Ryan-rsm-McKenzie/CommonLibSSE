#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHavok

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraHavok : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHavok;


		enum { kExtraTypeID = ExtraDataType::kHavok };


		virtual ~ExtraHavok();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kHavok; }


		// members
		NiPointer<NiRefObject>	unk10;	// 10
		NiPointer<NiRefObject>	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraHavok) == 0x20);
}
