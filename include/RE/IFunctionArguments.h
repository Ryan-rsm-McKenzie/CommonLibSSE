#pragma once

#include "RE/BSScriptVariable.h"  // BSScriptVariable
#include "RE/BSTArray.h"  // BSScrapArray
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	namespace BSScript
	{
		class IFunctionArguments
		{
		public:
			IFunctionArguments();
			virtual ~IFunctionArguments();									// 00

			// add
			virtual bool Copy(BSScrapArray<BSScriptVariable>& a_dst) = 0;	// 01

			TES_HEAP_REDEFINE_NEW();

		protected:
			static bool ResizeArguments(BSScrapArray<BSScriptVariable>& a_dst, UInt32 a_size);
		};
		STATIC_ASSERT(sizeof(IFunctionArguments) == 0x8);
	}
}
