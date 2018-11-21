#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class TESRace;


	class TESRaceForm : public BaseFormComponent
	{
	public:
		// members
		TESRace* race;	// 04
	};
}
