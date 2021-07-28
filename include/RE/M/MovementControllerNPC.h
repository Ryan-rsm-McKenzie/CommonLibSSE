#pragma once

#include "RE/I/IAnimationSetCallbackFunctor.h"
#include "RE/I/IMovementDirectControl.h"
#include "RE/I/IMovementMessageInterface.h"
#include "RE/I/IMovementMotionDrivenControl.h"
#include "RE/I/IMovementPlannerDirectControl.h"
#include "RE/I/IMovementSelectIdle.h"
#include "RE/M/MovementControllerAI.h"

namespace RE
{
	class MovementControllerNPC :
		public MovementControllerAI,           // 000
		public IMovementMessageInterface,      // 120
		public IMovementMotionDrivenControl,   // 128
		public IMovementSelectIdle,            // 130
		public IMovementDirectControl,         // 138
		public IMovementPlannerDirectControl,  // 140
		public IAnimationSetCallbackFunctor    // 148
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementControllerNPC;

		~MovementControllerNPC() override;  // 00

		// add
		virtual void Unk_0A();  // 0A
		virtual void Unk_0B();  // 0B
		virtual void Unk_0C();  // 0C
		virtual void Unk_0D();  // 0D
		virtual void Unk_0E();  // 0E - { return unk1C5 == 0; }
		virtual void Unk_0F();  // 0F - { return unk1C5; }
		virtual void Unk_10();  // 10
		virtual void Unk_11();  // 11
		virtual void Unk_12();  // 12
		virtual void Unk_13();  // 13
		virtual void Unk_14();  // 14

		// members
		std::uint64_t unk150;  // 150
		std::uint64_t unk158;  // 158
		std::uint64_t unk160;  // 160
		std::uint64_t unk168;  // 168
		std::uint64_t unk170;  // 170
		std::uint64_t unk178;  // 178
		std::uint64_t unk180;  // 180
		std::uint64_t unk188;  // 188
		std::uint64_t unk190;  // 190
		std::uint64_t unk198;  // 198
		std::uint64_t unk1A0;  // 1A0
		std::uint64_t unk1A8;  // 1A8
		std::uint64_t unk1B0;  // 1B0
		std::uint64_t unk1B8;  // 1B8
		std::uint32_t unk1C0;  // 1C0
		std::uint8_t  unk1C4;  // 1C4
		std::uint8_t  unk1C5;  // 1C5
		std::uint16_t unk1C6;  // 1C6
		std::uint64_t unk1C8;  // 1C8
	};
	static_assert(sizeof(MovementControllerNPC) == 0x1D0);
}
