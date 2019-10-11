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
		virtual void	Unk_0A(void);				// 0A - { return; }
		virtual void	Unk_0B(void);				// 0B - { return; }
		virtual void	Unk_0C(void);				// 0C - { return 0; }
		virtual void	Unk_0D(void);				// 0D
		virtual void	Unk_0E(void);				// 0E - { return; }


		// members
		SInt32	userIndex;		// C8
		bool	isConnected;	// CC
		bool	unkCD;			// CD
		UInt16	padCE;			// CE
	};
	STATIC_ASSERT(sizeof(BSGamepadDevice) == 0xD0);
}
