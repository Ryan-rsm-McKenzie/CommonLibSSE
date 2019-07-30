#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraOcclusionShape

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer



namespace RE
{
	class NiRefObject;


	class ExtraOcclusionShape : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraOcclusionShape;


		enum { kExtraTypeID = ExtraDataType::kOcclusionShape };


		virtual ~ExtraOcclusionShape();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kOcclusionShape; }


		// members
		NiPointer<NiRefObject> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOcclusionShape) == 0x18);
}
