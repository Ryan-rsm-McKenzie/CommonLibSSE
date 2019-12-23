#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESObjectSTAT;


	class BGSMenuDisplayObject : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSMenuDisplayObject;


		virtual ~BGSMenuDisplayObject();											// 00

		// override (BaseFormComponent)
		virtual void			InitializeDataComponent() override;					// 01
		virtual void			ClearDataComponent() override;						// 02 - { return; }
		virtual void			CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual TESObjectSTAT*	GetMenuDisplayObject();								// 04 - { return menuDisplayObject; }


		// members
		TESObjectSTAT* menuDisplayObject;	// 08 - MDOB
	};
	STATIC_ASSERT(sizeof(BGSMenuDisplayObject) == 0x10);
}
