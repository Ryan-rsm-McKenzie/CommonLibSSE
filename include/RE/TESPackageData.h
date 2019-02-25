#pragma once


namespace RE
{
	class TESPackageData
	{
	public:
		virtual ~TESPackageData();		// 00

		// add
		virtual void	Unk_01(void);	// 01 - { return; }
		virtual void	Unk_02(void);	// 02 - { return 1; }
		virtual void	Unk_03(void);	// 03 - { return; }
		virtual void	Unk_04(void);	// 04 - { return; }
		virtual void	Unk_05(void);	// 05 - { return; }
	};
	STATIC_ASSERT(sizeof(TESPackageData) == 0x8);
}
