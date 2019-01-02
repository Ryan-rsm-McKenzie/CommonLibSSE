#pragma once


namespace RE
{
	class hkpPhantomListener
	{
	public:
		virtual ~hkpPhantomListener();	// 00

		// add
		virtual void	Unk_01(void);	// 01 - {}
		virtual void	Unk_02(void);	// 02 - {}
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04 - {}
	};
	STATIC_ASSERT(sizeof(hkpPhantomListener) == 0x8);
}
