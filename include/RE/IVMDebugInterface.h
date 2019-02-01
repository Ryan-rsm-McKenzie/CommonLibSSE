#pragma once


namespace RE
{
	namespace BSScript
	{
		class IVMDebugInterface
		{
		public:
			virtual ~IVMDebugInterface();	// 00

			// add
			virtual void	Unk_01(void);	// 01 - pure
		};
		STATIC_ASSERT(sizeof(IVMDebugInterface) == 0x8);
	}
}
