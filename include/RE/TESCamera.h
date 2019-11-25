#pragma once

#include "RE/BSTSmartPointer.h"
#include "RE/NiNode.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESCameraState;


	class TESCamera
	{
	public:
		inline static const void* RTTI = RTTI_TESCamera;


		virtual ~TESCamera();								// 00

		virtual void	SetNode(NiPointer<NiNode> a_node);	// 01 - { if (cameraNode != a_node) cameraNode = a_node; }
		virtual void	Update();							// 02

		UInt32 SetCameraState(TESCameraState* a_cameraState);


		// members
		float							rotZ;			// 08
		float							rotX;			// 0C
		NiPoint3						pos;			// 10
		float							zoom;			// 1C
		NiPointer<NiNode>				cameraNode;		// 20
		BSTSmartPointer<TESCameraState>	cameraState;	// 28
		UInt8							unk30;			// 30
		UInt8							pad31;			// 31
		UInt16							pad32;			// 32
		UInt32							pad34;			// 34
	};
	STATIC_ASSERT(sizeof(TESCamera) == 0x38);
}
