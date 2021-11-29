#pragma once

#include "RE/T/TESCamera.h"

namespace RE
{
	class RaceSexCamera : public TESCamera
	{
	public:
		inline static constexpr auto RTTI = RTTI_RaceSexCamera;

		~RaceSexCamera() override;  // 00

		// override (TESCamera)
		void SetCameraRoot(NiPointer<NiNode> a_root) override;  // 01
		void Update() override;                                 // 02

		// members
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
	};
	static_assert(sizeof(RaceSexCamera) == 0x58);
}
