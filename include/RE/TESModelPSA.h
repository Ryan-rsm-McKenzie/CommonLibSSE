#pragma once

#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class TESModelPSA : public TESModel
	{
	public:
		virtual ~TESModelPSA();	// 00
	};
	STATIC_ASSERT(sizeof(TESModelPSA) == 0x28);
}
