#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRoom

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraRoom : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRoom;


		enum { kExtraTypeID = ExtraDataType::kRoom };


		virtual ~ExtraRoom();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRoom; }


		// members
		NiPointer<NiRefObject> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRoom) == 0x18);
}
