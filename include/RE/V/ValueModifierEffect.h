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
		void Unk_01(void) override;  // 01
		void Unk_04(void) override;  // 04
		void Unk_06(void) override;  // 06
		void Unk_11(void) override;  // 11 - { return  1; };
		void Unk_12(void) override;  // 12

		~ValueModifierEffect() override;  // 13

		void Start() override;       // 14
		void Finish() override;      // 15
		void Unk_17(void) override;  // 17
		void Unk_18(void) override;  // 18

		// add
		virtual void Unk_19(void);  // 19
		virtual void Unk_1A(void);  // 1A
		virtual void Unk_1B(void);  // 1B
		virtual void Unk_1C(void);  // 1C
		virtual void Unk_1D(void);  // 1D
		virtual void Unk_1E(void);  // 1E
		virtual void Unk_1F(void);  // 1F
		virtual void Unk_20(void);  // 20

		// members
		ActorValue    actorValue;  // 90
		std::uint32_t pad94;       // 94
	};
	static_assert(sizeof(ValueModifierEffect) == 0x98);
}
