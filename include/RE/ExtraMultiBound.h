#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraMultiBound

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraMultiBound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMultiBound;


		enum { kExtraTypeID = ExtraDataType::kMultiBound };


		virtual ~ExtraMultiBound();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kMultiBound; }


		// members
		NiPointer<NiRefObject> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraMultiBound) == 0x18);
}
