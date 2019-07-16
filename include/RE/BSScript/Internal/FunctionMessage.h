#pragma once


namespace RE
{
	namespace BSScript
	{
		class Stack;


		namespace Internal
		{
			class RawFuncCallQuery;


			struct FunctionMessage
			{
			public:
				UInt64	unk00;	// 00
				Stack*	unk08;	// 08
				void*	unk10;	// 10
			};
			STATIC_ASSERT(sizeof(FunctionMessage) == 0x18);
		}
	}
}
