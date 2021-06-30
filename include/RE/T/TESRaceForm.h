#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESRace;

	class TESRaceForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRaceForm;

		~TESRaceForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01 - { race = 0; }
		void ClearDataComponent() override;                     // 02 - { return; }
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		TESRace* race;  // 08 - RNAM
	};
	static_assert(sizeof(TESRaceForm) == 0x10);
}
