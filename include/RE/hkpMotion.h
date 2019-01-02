#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpMotion : public hkReferencedObject
	{
	public:
		virtual ~hkpMotion();			// 00

		// add
		virtual void	Unk_02(void);	// 02
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04
		virtual void	Unk_05(void);	// 05 - pure
		virtual void	Unk_06(void);	// 06 - pure
		virtual void	Unk_07(void);	// 07 - pure
		virtual void	Unk_08(void);	// 08 - pure
		virtual void	Unk_09(void);	// 09 - pure
		virtual void	Unk_0A(void);	// 0A - pure
		virtual void	Unk_0B(void);	// 0B
		virtual void	Unk_0C(void);	// 0C
		virtual void	Unk_0D(void);	// 0D
		virtual void	Unk_0E(void);	// 0E
		virtual void	Unk_0F(void);	// 0F
		virtual void	Unk_10(void);	// 10
		virtual void	Unk_11(void);	// 11
		virtual void	Unk_12(void);	// 12 - pure
		virtual void	Unk_13(void);	// 13
		virtual void	Unk_14(void);	// 14 - pure
		virtual void	Unk_15(void);	// 15 - pure
		virtual void	Unk_16(void);	// 16 - pure
		virtual void	Unk_17(void);	// 17 - pure
		virtual void	Unk_18(void);	// 18 - pure
		virtual void	Unk_19(void);	// 19


		// members
		UInt64	unk010;	// 010
		UInt64	unk018;	// 018
		UInt64	unk020;	// 020
		UInt64	unk028;	// 028
		UInt64	unk030;	// 030
		UInt64	unk038;	// 038
		UInt64	unk040;	// 040
		UInt64	unk048;	// 048
		UInt64	unk050;	// 050
		UInt64	unk058;	// 058
		UInt64	unk060;	// 060
		UInt64	unk068;	// 068
		UInt64	unk070;	// 070
		UInt64	unk078;	// 078
		UInt64	unk080;	// 080
		UInt64	unk088;	// 088
		UInt64	unk090;	// 090
		UInt64	unk098;	// 098
		UInt64	unk0A0;	// 0A0
		UInt64	unk0A8;	// 0A8
		UInt64	unk0B0;	// 0B0
		UInt64	unk0B8;	// 0B8
		UInt64	unk0C0;	// 0C0
		UInt64	unk0C8;	// 0C8
		UInt64	unk0D0;	// 0D0
		UInt64	unk0D8;	// 0D8
		UInt64	unk0E0;	// 0E0
		UInt64	unk0E8;	// 0E8
		UInt64	unk0F0;	// 0F0
		UInt64	unk0F8;	// 0F8
		UInt64	unk100;	// 100
		UInt64	unk108;	// 108
		UInt64	unk110;	// 110
		UInt64	unk118;	// 118
		UInt64	unk120;	// 120
		UInt64	unk128;	// 128
		UInt64	unk130;	// 130
		UInt64	unk138;	// 138
	};
	STATIC_ASSERT(sizeof(hkpMotion) == 0x140);
}
