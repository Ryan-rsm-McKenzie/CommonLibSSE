#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementPlannerSetArbitration : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementPlannerSetArbitration;

		~IMovementPlannerSetArbitration() override;  // 00

		// add
		virtual void Unk_01(void) = 0;  // 01
		virtual void Unk_02(void) = 0;  // 02
		virtual void Unk_03(void) = 0;  // 03
		virtual void Unk_04(void) = 0;  // 04
		virtual void Unk_05(void) = 0;  // 05
		virtual void Unk_06(void) = 0;  // 06
	};
	static_assert(sizeof(IMovementPlannerSetArbitration) == 0x8);
}
