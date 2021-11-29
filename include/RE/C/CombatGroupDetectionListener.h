#pragma once

#include "RE/D/DetectionListener.h"

namespace RE
{
	class CombatGroupDetectionListener : public DetectionListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatGroupDetectionListener;

		~CombatGroupDetectionListener() override;  // 00

		// override (DetectionListener)
		void Unk_02(void) override;  // 01

		// add
		virtual void Unk_05(void);  // 01 - { unk10 = 0; }

		// members
		void* unk10;  // 10
	};
	static_assert(sizeof(CombatGroupDetectionListener) == 0x18);
}
