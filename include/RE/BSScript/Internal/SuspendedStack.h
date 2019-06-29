#pragma once


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			struct SuspendedStack
			{
			public:
				void*	unk00;	// 00
				void*	unk08;	// 08
			};
			STATIC_ASSERT(sizeof(SuspendedStack) == 0x10);
		}
	}
}
