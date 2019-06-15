#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESModelPSA

#include "RE/TESModel.h"  // TESModel


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
