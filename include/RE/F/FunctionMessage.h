#pragma once

#include "RE/B/BSTSmartPointer.h"

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
				Type                            type;       // 00
				std::uint32_t                   pad04;      // 04
				BSTSmartPointer<Stack>          stack;      // 08
				BSTSmartPointer<IFuncCallQuery> funcQuery;  // 10
			};
			static_assert(sizeof(FunctionMessage) == 0x18);
		}
	}
}
