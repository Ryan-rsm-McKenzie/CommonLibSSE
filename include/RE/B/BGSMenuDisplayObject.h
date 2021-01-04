#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESBoundObject;

	class BGSMenuDisplayObject : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMenuDisplayObject;

		virtual ~BGSMenuDisplayObject();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual TESBoundObject* GetMenuDisplayObject() const;  // 04 - { return menuDispObject; }

		// members
		TESBoundObject* menuDispObject;	 // 08 - MDOB
	};
	static_assert(sizeof(BGSMenuDisplayObject) == 0x10);
}
