#pragma once

#include "skse64/GameTypes.h"  // BSIntrusiveRefCounted


namespace RE
{
	class TESCamera;


	class TESCameraState : public BSIntrusiveRefCounted
	{
	public:
		virtual ~TESCameraState();				// 00

		// add
		virtual void	OnStateStart();			// 01 - {}
		virtual void	OnStateEnd();			// 02 - {}
		virtual void	OnUpdate(void* a_arg1);	// 03
		virtual void	Unk_04(void);			// 04
		virtual void	Unk_05(void);			// 05
		virtual void	Unk_06(void);			// 06 - {}
		virtual void	Unk_07(void);			// 07 - {}
		virtual void	Unk_08(void);			// 08 - {}


		// members
		TESCamera*	camera;		// 10
		UInt32		stateId;	// 18
		UInt32		pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(TESCameraState) == 0x20);
}
