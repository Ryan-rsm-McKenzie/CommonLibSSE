#pragma once

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class NiPoint3;
	class NiQuaternion;
	class TESCamera;


	class TESCameraState : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCameraState;


		virtual ~TESCameraState();	// 00

		// add
		virtual void Begin();												// 01 - { return; }
		virtual void End();													// 02 - { return; }
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);	// 03
		virtual void GetRotation(NiQuaternion& a_rotation);					// 04
		virtual void GetTranslation(NiPoint3& a_translation);				// 05
		virtual void SaveGame(BGSSaveFormBuffer* a_buf);					// 06 - { return; }
		virtual void LoadGame(BGSLoadFormBuffer* a_buf);					// 07 - { return; }
		virtual void Revert(BGSLoadFormBuffer* a_buf);						// 08 - { return; }


		// members
		UInt32	   pad0C;	// 0C
		TESCamera* camera;	// 10
		UInt32	   id;		// 18
		UInt32	   pad1C;	// 1C
	};
	STATIC_ASSERT(sizeof(TESCameraState) == 0x20);
}
