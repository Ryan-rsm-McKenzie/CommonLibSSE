#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPortal

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraPortal : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPortal;


		enum { kExtraTypeID = ExtraDataType::kPortal };


		virtual ~ExtraPortal();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPortal; }


		// members
		NiPointer<NiRefObject> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPortal) == 0x18);
}
