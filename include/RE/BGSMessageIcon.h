#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMessageIcon

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/TESIcon.h"  // TESIcon


namespace RE
{
	class BGSMessageIcon : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSMessageIcon;


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
