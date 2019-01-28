#pragma once

#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class TESModelRDT : public TESModel
	{
	public:
		virtual ~TESModelRDT();	// 00
	};
	STATIC_ASSERT(sizeof(TESModelRDT) == 0x28);
}
