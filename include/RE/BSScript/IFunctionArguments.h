#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IFunctionArguments

#include "RE/BSScript/Variable.h"  // BSScript::Variable
#include "RE/BSTArray.h"  // BSScrapArray
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


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

		protected:
			static bool ResizeArguments(BSScrapArray<Variable>& a_dst, UInt32 a_size);
		};
		STATIC_ASSERT(sizeof(IFunctionArguments) == 0x8);
	}
}
