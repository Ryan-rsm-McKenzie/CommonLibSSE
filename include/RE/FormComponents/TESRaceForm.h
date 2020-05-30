#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESRace;


	class TESRaceForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRaceForm;


		virtual ~TESRaceForm();	 // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { race = 0; }
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESRace* race;	// 08 - RNAM
	};
	STATIC_ASSERT(sizeof(TESRaceForm) == 0x10);
}
