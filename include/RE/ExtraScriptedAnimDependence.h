#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTTuple.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraScriptedAnimDependence : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraScriptedAnimDependence;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kScriptedAnimDependence;


		virtual ~ExtraScriptedAnimDependence();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kScriptedAnimDependence; }


		// members
		BSTArray<BSTTuple<ObjectRefHandle, UInt32>> dependentManagers;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraScriptedAnimDependence) == 0x28);
}
