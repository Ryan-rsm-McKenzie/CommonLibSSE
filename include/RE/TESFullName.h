#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		// add
		virtual UInt32		GetFullNameLength();	// 04
		virtual const char*	GetName();				// 05


		// members
		BSFixedString name;	// 08
	};
	STATIC_ASSERT(sizeof(TESFullName) == 0x10);
}