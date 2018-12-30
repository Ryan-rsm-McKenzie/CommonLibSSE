#pragma once

#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	class NiNode;
	class TESCameraState;


	class TESCamera
	{
	public:
		virtual ~TESCamera();						// 00

		virtual void	SetNode(NiNode* a_node);	// 01
		virtual void	Update();					// 02

		UInt32			SetCameraState(TESCameraState* a_cameraState);


		// members
		float			rotZ;			// 08
		float			rotX;			// 0C
		NiPoint3		pos;			// 10
		float			zoom;			// 1C
		NiNode*			cameraNode;		// 20
		TESCameraState*	cameraState;	// 28
		UInt8			unk30;			// 30
		UInt8			pad31;			// 31
		UInt16			pad32;			// 32
		UInt32			pad34;			// 34
	};
	STATIC_ASSERT(sizeof(TESCamera) == 0x38);
}
