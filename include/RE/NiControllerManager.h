#pragma once

#include "skse64/NiControllers.h"  // NiTimeController

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class NiControllerSequence;


	class NiControllerManager : public NiTimeController
	{
	public:
		NiControllerSequence* GetSequenceByName(const BSFixedString& a_name);

		// members
		NiTArray<NiControllerSequence*>	sequences;	// 50
	};
}
