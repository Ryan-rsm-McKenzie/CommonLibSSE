#pragma once


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			struct FunctionMessage
			{
			public:
				UInt64	unk00;	// 00
				UInt64	unk08;	// 08
				UInt64	unk10;	// 10
			};
			STATIC_ASSERT(sizeof(FunctionMessage) == 0x18);
		}
	}
}
