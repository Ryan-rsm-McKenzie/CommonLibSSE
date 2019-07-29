#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCell3D

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	class ExtraCell3D : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCell3D;


		enum { kExtraTypeID = ExtraDataType::kCell3D };


		virtual ~ExtraCell3D();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCell3D; }


		// members
		NiPointer<NiRefObject> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCell3D) == 0x18);
}
