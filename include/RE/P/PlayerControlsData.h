#pragma once

#include "RE/N/NiPoint2.h"

namespace RE
{
	class PlayerControlsData
	{
	public:
		// members
		NiPoint2      moveInputVec;   // 00
		NiPoint2      lookInputVec;   // 08
		NiPoint2      prevMoveVec;    // 10
		NiPoint2      prevLookVec;    // 18
		std::uint32_t unk20;          // 20
		bool          autoMove;       // 24
		bool          running;        // 25
		std::uint8_t  unk26;          // 26
		bool          fovSlideMode;   // 27
		bool          povScriptMode;  // 28
		bool          povBeastMode;   // 29
		std::uint8_t  unk2A;          // 2A
		std::uint8_t  unk2B;          // 2B
		bool          remapMode;      // 2C
		std::uint8_t  unk2D;          // 2D
		std::uint16_t unk2E;          // 2E
	};
	static_assert(sizeof(PlayerControlsData) == 0x30);
}
