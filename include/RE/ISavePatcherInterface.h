#pragma once


namespace RE
{
	namespace BSScript
	{
		class ISavePatcherInterface
		{
		public:
			virtual ~ISavePatcherInterface();	// 00

			// add
			virtual void	Unk_01(void);		// 01 - pure
		};
		STATIC_ASSERT(sizeof(ISavePatcherInterface) == 0x8);
	}
}
