#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESCameraState

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	class BGSLoadGameBuffer;
	class NiPoint3;
	class NiQuaternion;
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
		virtual void	GetRotation(NiQuaternion* a_rot);						// 04
		virtual void	GetPosition(NiPoint3* a_pos);							// 05
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
