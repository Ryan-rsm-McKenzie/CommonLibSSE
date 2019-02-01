#pragma once


namespace RE
{
	namespace SkyrimScript
	{
		class SavePatcher
		{
		public:
			virtual ~SavePatcher();	// 00
		};
		STATIC_ASSERT(sizeof(SavePatcher) == 0x8);
	}
}
