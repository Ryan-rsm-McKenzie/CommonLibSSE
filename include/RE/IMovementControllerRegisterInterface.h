#pragma once


namespace RE
{
	class IMovementControllerRegisterInterface
	{
	public:
		virtual ~IMovementControllerRegisterInterface();	// 00

		// add
		virtual void	Unk_01(void);						// 01 - pure
		virtual void	Unk_02(void);						// 02 - pure
		virtual void	Unk_03(void);						// 03 - pure
		virtual void	Unk_04(void);						// 04 - pure
	};
	STATIC_ASSERT(sizeof(IMovementControllerRegisterInterface) == 0x8);
}
