#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class BGSBehaviorGraphModel : TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBehaviorGraphModel;

		virtual ~BGSBehaviorGraphModel();  // 00

		// override (TESModel)
		virtual void SetModel(const char* a_model) override;  // 05
	};
	static_assert(sizeof(BGSBehaviorGraphModel) == 0x28);
}
