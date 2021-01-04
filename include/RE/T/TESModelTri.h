#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class TESModelTri : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelTri;

		virtual ~TESModelTri();	 // 00

		// override (TESModel)
		virtual void SetModel(const char* a_model) override;  // 05
	};
	static_assert(sizeof(TESModelTri) == 0x28);
}
