#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSKeywordForm

#include <optional>  // optional

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/BGSKeyword.h"  // BGSKeyword


namespace RE
{
	class BGSKeywordForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSKeywordForm;


		virtual ~BGSKeywordForm();												// 00

		// override (BaseFormComponent)
		virtual void		Init() override;									// 01 - { return; }
		virtual void		ReleaseRefs() override;								// 02
		virtual void		CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual bool		HasKeyword(BGSKeyword* a_keyword) const;			// 04
		virtual BGSKeyword*	GetDefaultKeyword();								// 05 - { return 0; }

		bool						HasKeyword(UInt32 a_formID) const;
		std::optional<BGSKeyword*>	GetKeywordAt(UInt32 a_idx);
		UInt32						GetSize() const;


		// members
		BGSKeyword**	keywords;		// 08 - KWDA
		UInt32			keywordCount;	// 10 - KSIZ
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(BGSKeywordForm) == 0x18);
}
