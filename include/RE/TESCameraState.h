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
		virtual void	OnStateStart();			// 01 - { return; }
		virtual void	OnStateEnd();			// 02 - { return; }
		virtual void	OnUpdate(void* a_arg1);	// 03
		virtual void	Unk_04(void);			// 04
		virtual void	Unk_05(void);			// 05
		virtual void	Unk_06(void);			// 06 - { return; }
		virtual void	Unk_07(void);			// 07 - { return; }
		virtual void	Unk_08(void);			// 08 - { return; }


		// members
		TESCamera*	camera;		// 10
		UInt32		stateID;	// 18
		UInt32		pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(TESCameraState) == 0x20);
}
