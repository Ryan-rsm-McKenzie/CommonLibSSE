#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSSoundDescriptorForm;
	class TESBoundObject;

	struct SEASON
	{
		enum : std::uint32_t
		{
			kNone = static_cast<std::uint32_t>(-1),
			kSpring = 0,
			kSummer,
			kFall,
			kWinter,

			kTotal,
		};
	};

	class TESProduceForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESProduceForm;

		~TESProduceForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;              // 01
		void ClearDataComponent() override;                   // 02 - { return; }
		void CopyComponent(BaseFormComponent* rhs) override;  // 03

		// members
		BGSSoundDescriptorForm* harvestSound;                   // 08 - SNAM
		TESBoundObject*         produceItem;                    // 10 - PFIG
		std::int8_t             produceChance[SEASON::kTotal];  // 18 - PFPC
		std::uint32_t           pad1C;                          // 1C
	};
	static_assert(sizeof(TESProduceForm) == 0x20);
}
