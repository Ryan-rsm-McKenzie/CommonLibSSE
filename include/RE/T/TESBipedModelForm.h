#pragma once

#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModelRDT.h"
#include "RE/T/TESModelTextureSwap.h"

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

		~TESBipedModelForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01
		void ClearDataComponent() override;                     // 02
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		TESModelTextureSwap worldModels[Sexes::kTotal];     // 08
		TESIcon             inventoryIcons[Sexes::kTotal];  // 78
		BGSMessageIcon      messageIcons[Sexes::kTotal];    // 98
		TESModelRDT         constraintTemplate;             // C8
	};
	static_assert(sizeof(TESBipedModelForm) == 0xF0);
}
