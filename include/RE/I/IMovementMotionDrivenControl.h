#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementMotionDrivenControl : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementMotionDrivenControl;

		~IMovementMotionDrivenControl() override;  // 00

		// add
		virtual void Unk_01() = 0;  // 01
		virtual void Unk_02() = 0;  // 02
		virtual void Unk_03() = 0;  // 03
		virtual void Unk_04() = 0;  // 04
		virtual void Unk_05() = 0;  // 05
		virtual void Unk_06() = 0;  // 06
		virtual void Unk_07() = 0;  // 07
		virtual void Unk_08() = 0;  // 08
	};
	static_assert(sizeof(IMovementMotionDrivenControl) == 0x8);
}
