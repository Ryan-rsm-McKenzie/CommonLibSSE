#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/ThirdPersonState.h"

namespace RE
{
	class NiAVObject;

	class BleedoutCameraState : public ThirdPersonState
	{
	public:
		inline static constexpr auto RTTI = RTTI_BleedoutCameraState;

		virtual ~BleedoutCameraState();	 // 00

		// override (ThirdPersonState)
		virtual void Begin() override;												 // 01
		virtual void End() override;												 // 02
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;	 // 03

		// members
		NiMatrix3			  rotationMtx;		  // 0E8
		float				  zoom;				  // 10C
		float				  pitch;			  // 110
		float				  yaw;				  // 114
		float				  randHeading;		  // 118
		std::uint32_t		  pad11C;			  // 11C
		NiPointer<NiAVObject> animatedBone;		  // 120
		BSSoundHandle		  activeSound;		  // 128
		bool				  useCurrentHeading;  // 134
		std::uint8_t		  pad135;			  // 135
		std::uint16_t		  pad136;			  // 136
	};
	static_assert(sizeof(BleedoutCameraState) == 0x138);
}
