#include "RE/B/BGSKeywordForm.h"

#include "RE/B/BGSKeyword.h"
#include "SKSE/Impl/Util.h"

namespace RE
{
	bool BGSKeywordForm::AddKeyword(BGSKeyword* a_keyword)
	{
		if (!GetKeywordIndex(a_keyword).has_value()) {
			auto oldData = keywords;
			keywords = calloc<BGSKeyword*>(++numKeywords);
			if (oldData) {
				for (std::uint32_t i = 0; i < numKeywords - 1; ++i) {
					keywords[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			keywords[numKeywords - 1] = a_keyword;
			return true;
		}
		return false;
	}

	bool BGSKeywordForm::ContainsKeywordString(std::string_view a_editorID) const
	{
		if (keywords) {
			for (std::uint32_t idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && stl::string::icontains(keywords[idx]->formEditorID, a_editorID)) {
					return true;
				}
			}
		}

		return false;
	}

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

	bool BGSKeywordForm::HasKeywordString(std::string_view a_editorID) const
	{
		if (keywords) {
			for (std::uint32_t idx = 0; idx < numKeywords; ++idx) {
				if (keywords[idx] && keywords[idx]->formEditorID == a_editorID) {
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

	std::optional<std::uint32_t> BGSKeywordForm::GetKeywordIndex(BGSKeyword* a_keyword) const
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (keywords) {
			for (std::uint32_t i = 0; i < numKeywords; ++i) {
				if (keywords[i] && keywords[i] == a_keyword) {
					index = i;
					break;
				}
			}
		}
		return index;
	}

	std::uint32_t BGSKeywordForm::GetNumKeywords() const
	{
		return numKeywords;
	}

	bool BGSKeywordForm::RemoveKeyword(std::uint32_t a_index)
	{
		auto oldData = keywords;
		if (oldData) {
			keywords = calloc<BGSKeyword*>(--numKeywords);
			for (std::uint32_t i = 0; i < numKeywords + 1; ++i) {
				if (i != a_index) {
					keywords[i] = oldData[i];
				}
			}
			free(oldData);
			oldData = nullptr;

			return true;
		}
		return false;
	}

	bool BGSKeywordForm::RemoveKeyword(BGSKeyword* a_keyword)
	{
		auto index = GetKeywordIndex(a_keyword);
		if (index.has_value()) {
			return RemoveKeyword(index.value());
		}
		return false;
	}
}
