#pragma once

#include "RE/A/ActiveEffect.h"
#include "RE/A/ActorValues.h"

namespace RE
{
	class ValueModifierEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ValueModifierEffect;

		// override (ActiveEffect)
		virtual void Unk_01() override;  // 01
		virtual void Unk_04() override;  // 04
		virtual void Unk_06() override;  // 06
		virtual void Unk_11() override;  // 11 - { return  1; };
		virtual void Unk_12() override;  // 12

		virtual ~ValueModifierEffect();  // 13

		virtual void Unk_14() override;  // 14
		virtual void Unk_15() override;  // 15
		virtual void Unk_17() override;  // 17
		virtual void Unk_18() override;  // 18

		// add
		virtual void Unk_19();  // 19
		virtual void Unk_1A();  // 1A
		virtual void Unk_1B();  // 1B
		virtual void Unk_1C();  // 1C
		virtual void Unk_1D();  // 1D
		virtual void Unk_1E();  // 1E
		virtual void Unk_1F();  // 1F
		virtual void Unk_20();  // 20

		// members
		ActorValue    actorValue;  // 90
		std::uint32_t pad94;       // 94
	};
	static_assert(sizeof(ValueModifierEffect) == 0x98);
}
