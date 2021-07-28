#include "RE/B/BGSKeywordForm.h"

#include "RE/B/BGSKeyword.h"

namespace RE
{
	bool BGSKeywordForm::HasKeyword(FormID a_formID) const
	{
		if (keywords) {
			for (std::uint32_t idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formID == a_formID) {
					return true;
				}
			}
		}

		return false;
	}

	std::optional<BGSKeyword*> BGSKeywordForm::GetKeywordAt(std::uint32_t a_idx) const
	{
		if (a_idx < numKeywords) {
			return std::make_optional(keywords[a_idx]);
		} else {
			return std::nullopt;
		}
	}

	std::uint32_t BGSKeywordForm::GetNumKeywords() const
	{
		return numKeywords;
	}
}
