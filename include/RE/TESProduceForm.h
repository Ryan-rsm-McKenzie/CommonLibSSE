#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSSoundDescriptorForm;
	class TESBoundObject;


	class TESProduceForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESProduceForm;


		struct IngredientProduction	// PFPC
		{
			UInt8	spring;	// 0
			UInt8	summer;	// 1
			UInt8	fall;	// 2
			UInt8	winter;	// 3
		};
		STATIC_ASSERT(sizeof(IngredientProduction) == 0x4);


		virtual ~TESProduceForm();										// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;				// 01
		virtual void	ClearDataComponent() override;					// 02 - { return; }
		virtual void	CopyComponent(BaseFormComponent* rhs) override;	// 03


		// members
		BGSSoundDescriptorForm*	sound;					// 08 - SNAM
		TESBoundObject*			ingredient;				// 10 - PFIG
		IngredientProduction	ingredientProduction;	// 18 - PFPC
		UInt32					unk1C;					// 1C
	};
	STATIC_ASSERT(sizeof(TESProduceForm) == 0x20);
}
