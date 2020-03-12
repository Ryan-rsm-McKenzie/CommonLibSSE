#pragma once

#include "RE/BGSMessageIcon.h"
#include "RE/BaseFormComponent.h"
#include "RE/TESIcon.h"
#include "RE/TESModelRDT.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	class TESBipedModelForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESBipedModelForm;


		struct Sexes
		{
			enum
			{
				kMale = 0,
				kFemale,
				kTotal
			};
		};


		virtual ~TESBipedModelForm();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESModelTextureSwap worldModels[Sexes::kTotal];		// 08
		TESIcon				inventoryIcons[Sexes::kTotal];	// 78
		BGSMessageIcon		messageIcons[Sexes::kTotal];	// 98
		TESModelRDT			constraintTemplate;				// C8
	};
	STATIC_ASSERT(sizeof(TESBipedModelForm) == 0xF0);
}
