#pragma once

#include <optional>

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSKeyword;


	class BGSKeywordForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSKeywordForm;


		virtual ~BGSKeywordForm();												// 00

		// override (BaseFormComponent)
		virtual void		InitializeDataComponent() override;					// 01 - { return; }
		virtual void		ClearDataComponent() override;						// 02
		virtual void		CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual bool		HasKeyword(BGSKeyword* a_keyword) const;			// 04
		virtual BGSKeyword*	GetKeywordType();									// 05 - { return 0; }

		bool						HasKeyword(FormID a_formID) const;
		std::optional<BGSKeyword*>	GetKeywordAt(UInt32 a_idx);
		UInt32						GetNumKeywords() const;


		// members
		BGSKeyword**	keywords;		// 08 - KWDA
		UInt32			numKeywords;	// 10 - KSIZ
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(BGSKeywordForm) == 0x18);
}
