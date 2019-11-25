#pragma once

#include "RE/TESMemoryManager.h"


namespace RE
{
	class BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BaseFormComponent;


		virtual ~BaseFormComponent();							// 00

		// add
		virtual void	Init() = 0;								// 01
		virtual void	ReleaseRefs() = 0;						// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs);	// 03 - { return; }

		TES_HEAP_REDEFINE_NEW();
	};
	STATIC_ASSERT(sizeof(BaseFormComponent) == 0x8);
}
