#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESProduceForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // BGSSoundDescriptorForm


namespace RE
{
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
		virtual void	Init() override;								// 01
		virtual void	ReleaseRefs() override;							// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* rhs) override;	// 03


		// members
		BGSSoundDescriptorForm*	sound;					// 08 - SNAM
		IngredientItem*			ingredient;				// 10 - PFIG
		IngredientProduction	ingredientProduction;	// 18 - PFPC
		UInt32					unk1C;					// 1C
	};
	STATIC_ASSERT(sizeof(TESProduceForm) == 0x20);
}
