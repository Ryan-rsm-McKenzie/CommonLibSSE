#pragma once

#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class Stack;


		namespace Internal
		{
			class IFuncCallQuery;


			struct FunctionMessage
			{
			public:
				enum class Type
				{
					kInvalid = 0,
					kCall = 1,
					kReturn = 2
				};


				// members
				Type							type;		// 00
				UInt32							pad04;		// 04
				BSTSmartPointer<Stack>			stack;		// 08
				BSTSmartPointer<IFuncCallQuery> funcQuery;	// 10
			};
			STATIC_ASSERT(sizeof(FunctionMessage) == 0x18);
		}
	}
}
