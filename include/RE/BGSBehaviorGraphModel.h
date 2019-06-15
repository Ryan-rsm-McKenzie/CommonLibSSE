#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSBehaviorGraphModel

#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSBehaviorGraphModel : TESModel
	{
	public:
		inline static const void* RTTI = RTTI_BGSBehaviorGraphModel;


		virtual ~BGSBehaviorGraphModel();						// 00

		// override (TESModel)
		virtual void	SetModelName(const char* a_modelName);	// 05
	};
	STATIC_ASSERT(sizeof(BGSBehaviorGraphModel) == 0x28);
}
