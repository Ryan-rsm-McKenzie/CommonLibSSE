#pragma once

#include "RE/BSInputDevice.h"  // BSInputDevice


namespace RE
{
	class BSGamepadDevice : public BSInputDevice
	{
	public:
		virtual ~BSGamepadDevice();					// 00

		// override (BSInputDevice)
		virtual bool	IsEnabled() const override;	// 07 - { return isConnected && userIndex != -1; }

		// add
		virtual void	Unk_09(void);				// 09 - pure
		virtual void	Unk_0A(void);				// 0A
		virtual void	Unk_0B(void);				// 0B
		virtual void	Unk_0C(void);				// 0C
		virtual void	Unk_0D(void);				// 0D
		virtual void	Unk_0E(void);				// 0E


		// members
		UInt64	unk70;			// 70
		UInt64	unk78;			// 78
		UInt64	unk80;			// 80
		UInt64	unk88;			// 88
		UInt64	unk90;			// 90
		UInt64	unk98;			// 98
		UInt64	unkA0;			// A0
		UInt64	unkA8;			// A8
		UInt64	unkB0;			// B0
		UInt64	unkB8;			// B8
		UInt64	unkC0;			// C0
		SInt32	userIndex;		// C8 - init'd -1
		bool	isConnected;	// CC - init'd false
		bool	unkCD;			// CD - init'd false
		UInt16	padCE;			// CE
	};
	STATIC_ASSERT(offsetof(BSGamepadDevice, userIndex) == 0xC8);
	STATIC_ASSERT(offsetof(BSGamepadDevice, isConnected) == 0xCC);
	STATIC_ASSERT(sizeof(BSGamepadDevice) == 0xD0);
}
