#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class TESModelTri : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelTri;

		~TESModelTri() override;  // 00

		// override (TESModel)
		void SetModel(const char* a_model) override;  // 05
	};
	static_assert(sizeof(TESModelTri) == 0x28);
}
