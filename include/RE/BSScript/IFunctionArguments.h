#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IFunctionArguments

#include "RE/BSScript/BSScriptVariable.h"  // BSScript::BSScriptVariable
#include "RE/BSTArray.h"  // BSScrapArray
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	namespace BSScript
	{
		class IFunctionArguments
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IFunctionArguments;


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
