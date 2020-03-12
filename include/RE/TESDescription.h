#pragma once

#include "RE/BGSLocalizedStringDL.h"
#include "RE/BSString.h"
#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESForm;


	class TESDescription : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESDescription;


		virtual ~TESDescription();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		void GetDescription(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType = 'CSED');


		// members
		UInt32				 fileOffset;	   // 08
		BGSLocalizedStringDL descriptionText;  // 0C
	};
	STATIC_ASSERT(sizeof(TESDescription) == 0x10);
}
