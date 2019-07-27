#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESCameraState

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BGSLoadGameBuffer;
	class TESCamera;


	class TESCameraState : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_TESCameraState;


		virtual ~TESCameraState();												// 00

		// add
		virtual void	OnStateStart();											// 01 - { return; }
		virtual void	OnStateEnd();											// 02 - { return; }
		virtual void	OnUpdate(BSTSmartPointer<TESCameraState>& a_newState);	// 03
		virtual void	Unk_04(void);											// 04
		virtual void	Unk_05(void);											// 05
		virtual void	Unk_06(void);											// 06 - { return; }
		virtual void	LoadCameraState(BGSLoadGameBuffer* a_buf);				// 07 - { return; }
		virtual void	Unk_08(void);											// 08 - { return; }


		// members
		UInt32		unk0C;		// 0C
		TESCamera*	camera;		// 10
		UInt32		stateID;	// 18
		UInt32		pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(TESCameraState) == 0x20);
}
