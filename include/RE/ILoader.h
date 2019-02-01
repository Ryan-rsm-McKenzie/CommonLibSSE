#pragma once


namespace RE
{
	namespace BSScript
	{
		struct ILoader
		{
		public:
			virtual ~ILoader();				// 00

			// add
			virtual void	Unk_01(void);	// 01 - pure
			virtual void	Unk_02(void);	// 02 - pure
			virtual void	Unk_03(void);	// 03 - pure
		};
		STATIC_ASSERT(sizeof(ILoader) == 0x8);
	}
}
