#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMenuDisplayObject

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // TESObjectSTAT


namespace RE
{
	class BGSMenuDisplayObject : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSMenuDisplayObject;


		virtual ~BGSMenuDisplayObject();											// 00

		// override (BaseFormComponent)
		virtual void			Init() override;									// 01
		virtual void			ReleaseRefs() override;								// 02 - { return; }
		virtual void			CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual TESObjectSTAT*	GetMenuDisplayObject();								// 04 - { return menuDisplayObject; }


		// members
		TESObjectSTAT* menuDisplayObject;	// 08 - MDOB
	};
	STATIC_ASSERT(sizeof(BGSMenuDisplayObject) == 0x10);
}
