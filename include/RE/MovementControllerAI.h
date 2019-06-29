#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MovementControllerAI

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/IMovementControllerRegisterInterface.h"  // IMovementControllerRegisterInterface


namespace RE
{
	class MovementControllerAI :
		public BSIntrusiveRefCounted,				// 008
		public IMovementControllerRegisterInterface	// 000
	{
	public:
		inline static const void* RTTI = RTTI_MovementControllerAI;


		virtual ~MovementControllerAI();	// 00

		// add
		virtual void	Unk_05(void);		// 05
		virtual void	Unk_06(void);		// 06 - { return; }
		virtual void	Unk_07(void);		// 07
		virtual void	Unk_08(void);		// 08
		virtual void	Unk_09(void);		// 09 - { return 1; }


		// members
		UInt32	unk00C;	// 00C
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
	};
	STATIC_ASSERT(sizeof(MovementControllerAI) == 0x120);
}
