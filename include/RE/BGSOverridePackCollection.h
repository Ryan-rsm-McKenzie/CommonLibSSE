#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSOverridePackCollection : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSOverridePackCollection;


		virtual ~BGSOverridePackCollection();								// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01
		virtual void	ClearDataComponent() override;						// 02 - { return; }
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		UInt64	unk08;	// 08
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(BGSOverridePackCollection) == 0x28);
}
