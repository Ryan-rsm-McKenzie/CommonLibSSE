#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class DetectionState : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_DetectionState;

		~DetectionState() override;  // 00

		// members
		std::int32_t level;  // 10
		std::uint8_t unk14;  // 14
		std::uint8_t unk15;  // 15
		std::uint8_t unk16;  // 16
		std::uint8_t pad17;  // 17
		float        unk18;  // 18
		NiPoint3     unk1C;  // 1C
		float        unk28;  // 28
		NiPoint3     unk2C;  // 2C
		float        unk38;  // 38
		NiPoint3     unk3C;  // 3C
	};
	static_assert(sizeof(DetectionState) == 0x48);
}
