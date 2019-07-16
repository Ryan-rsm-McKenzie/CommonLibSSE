#pragma once

#include "RE/BSScript/Stack.h"  // BSScript::Stack


namespace RE
{
	namespace BSScript
	{
		class Stack;


		namespace Internal
		{
			class RawFuncCallQuery;


			struct SuspendedStack
			{
			public:
				BSTSmartPointer<Stack>				stack;	// 00
				BSTSmartPointer<RawFuncCallQuery>	unk08;	// 08
			};
			STATIC_ASSERT(sizeof(SuspendedStack) == 0x10);
		}
	}
}
