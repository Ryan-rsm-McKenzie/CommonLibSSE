#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/TESIcon.h"  // TESIcon


namespace RE
{
	class BGSMessageIcon : public BaseFormComponent
	{
	public:
		virtual ~BGSMessageIcon();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02 - { icon.ReleaseRefs(); }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESIcon	icon;	// 08
	};
	STATIC_ASSERT(sizeof(BGSMessageIcon) == 0x18);
}
