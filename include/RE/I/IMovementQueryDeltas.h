#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementQueryDeltas : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementQueryDeltas;

		~IMovementQueryDeltas() override;  // 00

		// add
		virtual void Unk_01(void) = 0;  // 01
		virtual void Unk_02(void) = 0;  // 02
		virtual void Unk_03(void) = 0;  // 03
		virtual void Unk_04(void) = 0;  // 04
	};
	static_assert(sizeof(IMovementQueryDeltas) == 0x8);
}
