#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSEntryPointFunctionDataOneValue

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData


namespace RE
{
	class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
	{
	public:
		inline static const void* RTTI = RTTI_BGSEntryPointFunctionDataOneValue;


		virtual ~BGSEntryPointFunctionDataOneValue();						// 00

		// override (BGSEntryPointFunctionData)
		virtual FunctionType	GetType() const override;					// 01 - { return kOneValue; }
		virtual bool			LoadFunctionData(TESFile* a_mod) override;	// 02


		// members
		float	data;	// 08 - DATA
		UInt32	pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataOneValue) == 0x10);
}
