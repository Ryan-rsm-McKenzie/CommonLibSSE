#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementSetGoal : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementSetGoal;

		~IMovementSetGoal() override;  // 00

		// add
		virtual void Unk_01(void) = 0;  // 01
		virtual void Unk_02(void) = 0;  // 02
		virtual void Unk_03(void) = 0;  // 03
		virtual void Unk_04(void) = 0;  // 04
	};
	static_assert(sizeof(IMovementSetGoal) == 0x8);
}
