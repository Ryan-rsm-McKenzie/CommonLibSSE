#pragma once

#include "RE/TESModel.h"


namespace RE
{
	class TESModelRDT : public TESModel
	{
	public:
		inline static const void* RTTI = RTTI_TESModelRDT;


		virtual ~TESModelRDT();	// 00
	};
	STATIC_ASSERT(sizeof(TESModelRDT) == 0x28);
}
