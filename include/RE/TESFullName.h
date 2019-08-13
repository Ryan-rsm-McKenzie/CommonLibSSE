#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESFullName

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESFullName;


		virtual ~TESFullName();

		// override (BaseFormComponent)
		virtual void		Init() override;									// 01 - { name = ""; }
		virtual void		ReleaseRefs() override;								// 02 - { return; }
		virtual void		CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt32		GetFullNameLength();								// 04
		virtual const char*	GetName();											// 05


		// members
		BSFixedString name;	// 08 - FULL
	};
	STATIC_ASSERT(sizeof(TESFullName) == 0x10);
}
