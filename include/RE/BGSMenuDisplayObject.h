#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class TESObjectSTAT;


	class BGSMenuDisplayObject : public BaseFormComponent
	{
	public:
		virtual ~BGSMenuDisplayObject();											// 00

		// override (BaseFormComponent)
		virtual void			Init() override;									// 01
		virtual void			ReleaseRefs() override;								// 02 - {}
		virtual void			CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual TESObjectSTAT*	GetMenuDisplayObject();								// 04 - { return worldStatic; }


		// members
		TESObjectSTAT* menuDisplayObject;	// 08 - MDOB
	};
	STATIC_ASSERT(sizeof(BGSMenuDisplayObject) == 0x10);
}
