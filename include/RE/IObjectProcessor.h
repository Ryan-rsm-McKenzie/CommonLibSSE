#pragma once


namespace RE
{
	namespace BSScript
	{
		class IObjectProcessor
		{
		public:
			virtual ~IObjectProcessor();	// 00

			// add
			virtual void	Unk_01(void);	// 01 - pure
			virtual void	Unk_02(void);	// 02 - pure
			virtual void	Unk_03(void);	// 03 - pure
		};
		STATIC_ASSERT(sizeof(IObjectProcessor) == 0x8);
	}
}
