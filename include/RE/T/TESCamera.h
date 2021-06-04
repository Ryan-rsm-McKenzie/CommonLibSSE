#pragma once

#include "RE/B/BSTPoint.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiNode.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESCameraState;

	class TESCamera
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCamera;

		virtual ~TESCamera();  // 00

		virtual void SetCameraRoot(NiPointer<NiNode> a_root);  // 01 - { if (cameraRoot != a_root) cameraRoot = a_root; }
		virtual void Update();                                 // 02

		void SetState(TESCameraState* a_state);

		// members
		BSTPoint2<float>                rotationInput;     // 08
		BSTPoint3<float>                translationInput;  // 10
		float                           zoomInput;         // 1C
		NiPointer<NiNode>               cameraRoot;        // 20
		BSTSmartPointer<TESCameraState> currentState;      // 28
		bool                            enabled;           // 30
		std::uint8_t                    pad31;             // 31
		std::uint16_t                   pad32;             // 32
		std::uint32_t                   pad34;             // 34
	};
	static_assert(sizeof(TESCamera) == 0x38);
}
