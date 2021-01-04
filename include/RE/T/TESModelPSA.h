#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class TESModelPSA : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelPSA;

		virtual ~TESModelPSA();	 // 00
	};
	static_assert(sizeof(TESModelPSA) == 0x28);
}
