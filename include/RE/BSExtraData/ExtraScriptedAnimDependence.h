#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTTuple.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


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
