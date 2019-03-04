#pragma once

#include "RE/hkbGenerator.h"  // hkbGenerator


namespace RE
{
	class hkbStateMachine : public hkbGenerator
	{
	public:
		virtual ~hkbStateMachine();				// 00

		// override (hkbGenerator)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_02(void) override;	// 02
		virtual void	Unk_03(void) override;	// 03
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_05(void) override;	// 05
		virtual void	Unk_06(void) override;	// 06
		virtual void	Unk_07(void) override;	// 07
		virtual void	Unk_08(void) override;	// 08
		virtual void	Unk_09(void) override;	// 09
		virtual void	Unk_0A(void) override;	// 0A
		virtual void	Unk_0C(void) override;	// 0C
		virtual void	Unk_0D(void) override;	// 0D
		virtual void	Unk_0E(void) override;	// 0E
		virtual void	Unk_0F(void) override;	// 0F
		virtual void	Unk_10(void) override;	// 10
		virtual void	Unk_11(void) override;	// 11
		virtual void	Unk_12(void) override;	// 12
		virtual void	Unk_14(void) override;	// 14
		virtual void	Unk_17(void) override;	// 17
		virtual void	Unk_18(void) override;	// 18 - { return 1; }
		virtual void	Unk_19(void) override;	// 19
		virtual void	Unk_1B(void) override;	// 1B - { unk101 = 1; }


		// members
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
		UInt8	unk100;	// 100
		UInt8	unk101;	// 101
		UInt16	unk102;	// 102
		UInt32	unk104;	// 104
	};
	STATIC_ASSERT(sizeof(hkbStateMachine) == 0x108);
}
