#include "RE/BGSKeywordForm.h"

#include "RE/BGSKeyword.h"


namespace RE
{
	bool BGSKeywordForm::HasKeyword(FormID a_formID) const
	{
		if (keywords) {
			for (UInt32 idx = 0; idx < keywordCount; ++idx) {
				if (keywords[idx] && keywords[idx]->formID == a_formID) {
					return true;
				}
			}
		}

		return false;
	}


	std::optional<BGSKeyword*> BGSKeywordForm::GetKeywordAt(UInt32 a_idx)
	{
		if (a_idx < keywordCount) {
			return std::make_optional(keywords[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	UInt32 BGSKeywordForm::GetSize() const
	{
		return keywordCount;
	}
}
