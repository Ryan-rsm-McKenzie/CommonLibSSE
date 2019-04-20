#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESValueForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class TESValueForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESValueForm;


		virtual ~TESValueForm();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		UInt32	value;	// 08
		UInt32	pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(TESValueForm) == 0x10);
}
