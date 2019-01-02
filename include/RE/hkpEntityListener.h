#pragma once


namespace RE
{
	class hkpEntityListener
	{
	public:
		virtual ~hkpEntityListener();	// 00

		// add
		virtual void	Unk_01(void);	// 01 - {}
		virtual void	Unk_02(void);	// 02 - {}
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04 - {}
		virtual void	Unk_05(void);	// 05 - {}
	};
	STATIC_ASSERT(sizeof(hkpEntityListener) == 0x8);
}
