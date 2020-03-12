#pragma once

#include "RE/TESModel.h"


namespace RE
{
	class TESModelRDT : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelRDT;


		virtual ~TESModelRDT();	 // 00
	};
	STATIC_ASSERT(sizeof(TESModelRDT) == 0x28);
}
