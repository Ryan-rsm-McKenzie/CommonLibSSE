#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESQualityForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESQualityForm;


		enum class Quality : UInt32
		{
			kNovice = 0,
			kApprentice = 1,
			kJourneyman = 2,
			kExpert = 3,
			kMaster = 4
		};


		virtual ~TESQualityForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { quality = 0; }
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		Quality quality;  // 08 - QUAL
		UInt32	pad0C;	  // 0C
	};
	STATIC_ASSERT(sizeof(TESQualityForm) == 0x10);
}
