#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementQueryTweener : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementQueryTweener;

		~IMovementQueryTweener() override;  // 00

		// add
		virtual void Unk_01(void) = 0;  // 01
		virtual void Unk_02(void) = 0;  // 02
		virtual void Unk_03(void) = 0;  // 03
	};
	static_assert(sizeof(IMovementQueryTweener) == 0x8);
}
