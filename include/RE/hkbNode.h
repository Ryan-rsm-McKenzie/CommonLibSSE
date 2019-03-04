#pragma once

#include "RE/hkbBindable.h"  // hkbBindable


namespace RE
{
	class hkbNode : public hkbBindable
	{
	public:
		virtual ~hkbNode();				// 00

		// add
		virtual void	Unk_04(void);	// 04 - { return; }
		virtual void	Unk_05(void);	// 05 - { unk30 |= 1; }
		virtual void	Unk_06(void);	// 06 - { return; }
		virtual void	Unk_07(void);	// 07 - { return; }
		virtual void	Unk_08(void);	// 08 - { return 2; }
		virtual void	Unk_09(void);	// 09 - { return; }
		virtual void	Unk_0A(void);	// 0A - { return 1; }
		virtual void	Unk_0B(void);	// 0B - { return; }
		virtual void	Unk_0C(void);	// 0C
		virtual void	Unk_0D(void);	// 0D - { return 0; }
		virtual void	Unk_0E(void);	// 0E - { return; }
		virtual void	Unk_0F(void);	// 0F - { return; }
		virtual void	Unk_10(void);	// 10 - { return; }
		virtual void	Unk_11(void);	// 11 - { return; }
		virtual void	Unk_12(void);	// 12 - { return; }
		virtual void	Unk_13(void);	// 13 - { return 0; }
		virtual void	Unk_14(void);	// 14 - { return; }
		virtual void	Unk_15(void);	// 15 - { return 0; }
		virtual void	Unk_16(void);	// 16 - { return 0; }


		// members
		UInt64		unk30;		// 30
		const char*	nodeName;	// 38
		UInt64		unk40;		// 40
	};
	STATIC_ASSERT(sizeof(hkbNode) == 0x48);
}
