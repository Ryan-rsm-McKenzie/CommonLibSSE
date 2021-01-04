#pragma once

#include "RE/H/hkpCharacterState.h"

namespace RE
{
	class bhkCharacterState : public hkpCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterState;

		virtual ~bhkCharacterState();  // 00

		// override (hkpCharacterState)
		virtual void Update(hkpCharacterContext& a_context, const hkpCharacterInput& a_input, hkpCharacterOutput& a_output) override;  // 06
		virtual void Change(hkpCharacterContext& a_context, const hkpCharacterInput& a_input, hkpCharacterOutput& a_output) override;  // 07

		// add
		virtual void Unk_08(void) = 0;	// 08
	};
	static_assert(sizeof(bhkCharacterState) == 0x10);
}
