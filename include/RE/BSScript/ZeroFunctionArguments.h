#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__ZeroFunctionArguments

#include "RE/BSScript/IFunctionArguments.h"  // BSScript::IFunctionArguments


namespace RE
{
	namespace BSScript
	{
		class ZeroFunctionArguments : public IFunctionArguments
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__ZeroFunctionArguments;


			// override (IFunctionArguments)
			virtual bool Copy(BSScrapArray<Variable>& a_dst) override;	// 01
		};
		STATIC_ASSERT(sizeof(ZeroFunctionArguments) == 0x8);
	}
}
