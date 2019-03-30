#pragma once

#include "RE/IFunctionArguments.h"  // IFunctionArguments


namespace RE
{
	namespace BSScript
	{
		class ZeroFunctionArguments : public IFunctionArguments
		{
		public:
			// override (IFunctionArguments)
			virtual bool Copy(BSScrapArray<BSScriptVariable>& a_dst) override;	// 01
		};
		STATIC_ASSERT(sizeof(ZeroFunctionArguments) == 0x8);
	}
}
