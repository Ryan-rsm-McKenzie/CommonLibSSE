#pragma once


namespace RE
{
	namespace BSScript
	{
		class IStackCallbackSaveInterface
		{
		public:
			virtual ~IStackCallbackSaveInterface();	// 00

			// add
			virtual void	Unk_01(void) = 0;		// 01
			virtual void	Unk_02(void) = 0;		// 02
		};
		STATIC_ASSERT(sizeof(IStackCallbackSaveInterface) == 0x8);
	}
}
