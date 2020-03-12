#pragma once

#include "RE/MemoryManager.h"


namespace RE
{
	class BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BaseFormComponent;


		virtual ~BaseFormComponent();  // 00

		// add
		virtual void InitializeDataComponent() = 0;			   // 01
		virtual void ClearDataComponent() = 0;				   // 02
		virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03 - { return; }

		TES_HEAP_REDEFINE_NEW();
	};
	STATIC_ASSERT(sizeof(BaseFormComponent) == 0x8);
}
