#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSGamepadDevice

#include "RE/BSInputDevice.h"  // BSInputDevice
#include "RE/BSTEvent.h"  // BSTEventSource


namespace RE
{
	struct BSGamepadEvent;


	class BSGamepadDevice :
		public BSInputDevice,					// 00
		public BSTEventSource<BSGamepadEvent>	// 70
	{
	public:
		inline static const void* RTTI = RTTI_BSGamepadDevice;


		virtual ~BSGamepadDevice();					// 00

		// override (BSInputDevice)
		virtual bool	IsEnabled() const override;	// 07 - { return isConnected && userIndex != -1; }

		// add
		virtual void	Unk_09(void) = 0;			// 09
		virtual void	Unk_0A(void);				// 0A
		virtual void	Unk_0B(void);				// 0B
		virtual void	Unk_0C(void);				// 0C
		virtual void	Unk_0D(void);				// 0D
		virtual void	Unk_0E(void);				// 0E


		// members
		SInt32	userIndex;		// C8 - init'd -1
		bool	isConnected;	// CC - init'd false
		bool	unkCD;			// CD - init'd false
		UInt16	padCE;			// CE
	};
	STATIC_ASSERT(offsetof(BSGamepadDevice, userIndex) == 0xC8);
	STATIC_ASSERT(offsetof(BSGamepadDevice, isConnected) == 0xCC);
	STATIC_ASSERT(sizeof(BSGamepadDevice) == 0xD0);
}
