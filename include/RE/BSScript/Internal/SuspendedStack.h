#pragma once

#include "RE/BSScript/Stack.h"


namespace RE
{
	namespace BSScript
	{
		class Stack;


		namespace Internal
		{
			class IFuncCallQuery;


			struct SuspendedStack
			{
			public:
				BSTSmartPointer<Stack>			stack;			// 00
				BSTSmartPointer<IFuncCallQuery>	funcCallQuery;	// 08
			};
			STATIC_ASSERT(sizeof(SuspendedStack) == 0x10);
		}
	}
}
