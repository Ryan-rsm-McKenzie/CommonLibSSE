#pragma once

#include "RE/BSTPoint.h"
#include "RE/BSTSmartPointer.h"
#include "RE/NiNode.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESCameraState;


	class TESCamera
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCamera;


		virtual ~TESCamera();  // 00

		virtual void SetCameraRoot(NiPointer<NiNode> a_root);  // 01 - { if (cameraRoot != a_root) cameraRoot = a_root; }
		virtual void Update();								   // 02

		void SetState(TESCameraState* a_state);


		// members
		BSTPoint2<float>				rotationInput;	   // 08
		BSTPoint3<float>				translationInput;  // 10
		float							zoomInput;		   // 1C
		NiPointer<NiNode>				cameraRoot;		   // 20
		BSTSmartPointer<TESCameraState> curentState;	   // 28
		bool							enabled;		   // 30
		UInt8							pad31;			   // 31
		UInt16							pad32;			   // 32
		UInt32							pad34;			   // 34
	};
	STATIC_ASSERT(sizeof(TESCamera) == 0x38);
}
