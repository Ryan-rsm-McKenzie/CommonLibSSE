#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSIInputDevice


namespace RE
{
	class BSIInputDevice
	{
	public:
		inline static const void* RTTI = RTTI_BSIInputDevice;


		virtual ~BSIInputDevice();					// 00

		// add
		virtual void	Initialize() = 0;			// 01
		virtual	void	Process(float a_arg1) = 0;	// 02
		virtual	void	Unk_03(void) = 0;			// 03
		virtual	void	Unk_04(void) = 0;			// 04
		virtual void	Unk_05(void) = 0;			// 05
		virtual void	Unk_06(void) = 0;			// 06
		virtual bool	IsEnabled() const = 0;		// 07
		virtual void	Unk_08(void) = 0;			// 08
	};
	STATIC_ASSERT(sizeof(BSIInputDevice) == 0x8);
}
