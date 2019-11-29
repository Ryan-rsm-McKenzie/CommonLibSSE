#pragma once

#include "RE/BSScript/Variable.h"
#include "RE/BSTArray.h"
#include "RE/TESMemoryManager.h"


namespace RE
{
	namespace BSScript
	{
		class IFunctionArguments
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IFunctionArguments;


			IFunctionArguments() = default;
			virtual ~IFunctionArguments() = default;				// 00

			// add
			virtual bool Copy(BSScrapArray<Variable>& a_dst) = 0;	// 01

			TES_HEAP_REDEFINE_NEW();
		};
		STATIC_ASSERT(sizeof(IFunctionArguments) == 0x8);
	}
}
