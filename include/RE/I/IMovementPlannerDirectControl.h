#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementPlannerDirectControl : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementPlannerDirectControl;

		~IMovementPlannerDirectControl() override;  // 00

		// add
		virtual void Unk_01() = 0;  // 01
		virtual void Unk_02() = 0;  // 02
		virtual void Unk_03() = 0;  // 03
		virtual void Unk_04() = 0;  // 04
		virtual void Unk_05() = 0;  // 05
	};
	static_assert(sizeof(IMovementPlannerDirectControl) == 0x8);
}
