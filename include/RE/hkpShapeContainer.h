#pragma once


namespace RE
{
	class hkpShapeContainer
	{
	public:
		virtual ~hkpShapeContainer();	// 00

		// add
		virtual void	Unk_01(void);	// 01
		virtual void	Unk_02(void);	// 02
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04 - { return 0; }
		virtual void	Unk_05(void);	// 05
		virtual void	Unk_06(void);	// 06 - { return 1; }
	}
	STATIC_ASSERT(sizeof(hkpShapeContainer) == 0x8);
}
