#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSSoundDescriptorForm;
	class TESBoundObject;


	struct SEASON
	{
		enum : UInt32
		{
			kNone = static_cast<UInt32>(-1),
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


		virtual ~TESProduceForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;			  // 01
		virtual void ClearDataComponent() override;					  // 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* rhs) override;  // 03


		// members
		BGSSoundDescriptorForm* harvestSound;					// 08 - SNAM
		TESBoundObject*			produceItem;					// 10 - PFIG
		SInt8					produceChance[SEASON::kTotal];	// 18 - PFPC
		UInt32					pad1C;							// 1C
	};
	STATIC_ASSERT(sizeof(TESProduceForm) == 0x20);
}
