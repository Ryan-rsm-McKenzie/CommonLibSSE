#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraScriptedAnimDependence : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraScriptedAnimDependence;


		enum { kExtraTypeID = ExtraDataType::kScriptedAnimDependence };


		virtual ~ExtraScriptedAnimDependence();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kScriptedAnimDependence; }


		// members
		BSTArray<void*> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraScriptedAnimDependence) == 0x28);
}
