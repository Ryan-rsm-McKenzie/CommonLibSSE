#pragma once


namespace RE
{
	class IAIWorldLocationHandle
	{
	public:
		virtual ~IAIWorldLocationHandle();	// 00

		// add
		virtual void	Unk_00(void);	// 00 - pure
		virtual void	Unk_01(void);	// 01 - { return 0; }
		virtual void	Unk_02(void);	// 02 - pure
	};
	STATIC_ASSERT(sizeof(IAIWorldLocationHandle) == 0x8);
}
