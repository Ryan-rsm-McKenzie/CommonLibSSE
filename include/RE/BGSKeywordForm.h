#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BGSKeyword.h"  // BGSKeyword


namespace RE
{
	class BGSKeywordForm : public BaseFormComponent
	{
	public:
		virtual ~BGSKeywordForm();									// 00

		// add
		virtual bool	HasKeyword(BGSKeyword* a_keyword) const;	// 04
		virtual void*	GetDefaultKeyword();						// 05 - { return 0; }

		bool			HasKeyword(UInt32 a_formID) const;
		bool			GetKeywordAt(UInt32 a_idx, BGSKeyword*& a_keyword) const;
		UInt32			GetSize() const;


		// members
		BGSKeyword**	keywords;		// 08 - KWDA
		UInt32			keywordCount;	// 10 - KSIZ
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(BGSKeywordForm) == 0x18);
}
