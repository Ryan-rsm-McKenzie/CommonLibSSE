#include "RE/BGSKeywordForm.h"

#include "RE/BGSKeyword.h"  // BGSKeyword


namespace RE
{
	bool BGSKeywordForm::HasKeyword(UInt32 a_formID) const
	{
		if (keywords) {
			for (UInt32 idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formID == a_formID) {
					return true;
				}
			}
		}

		return false;
	}


	bool BGSKeywordForm::GetKeywordAt(UInt32 a_idx, BGSKeyword*& a_keyword) const
	{
		if (a_idx < numKeywords) {
			a_keyword = keywords[a_idx];
			return true;
		} else {
			return false;
		}
	}


	UInt32 BGSKeywordForm::GetSize() const
	{
		return numKeywords;
	}
}
