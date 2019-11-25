#pragma once

#include "RE/TESModel.h"


namespace RE
{
	class TESModelPSA : public TESModel
	{
	public:
		inline static const void* RTTI = RTTI_TESModelPSA;


		virtual ~TESModelPSA();	// 00
	};
	STATIC_ASSERT(sizeof(TESModelPSA) == 0x28);
}
