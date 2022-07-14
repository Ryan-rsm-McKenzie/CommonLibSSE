#include "RE/B/BGSKeywordForm.h"

#include "RE/B/BGSKeyword.h"
#include "SKSE/Impl/Util.h"

namespace RE
{
	bool BGSKeywordForm::AddKeyword(BGSKeyword* a_keyword)
	{
		if (!GetKeywordIndex(a_keyword)) {
			std::vector<BGSKeyword*> copiedData{ keywords, keywords + numKeywords };
			copiedData.push_back(a_keyword);

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<BGSKeyword*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = keywords;

			numKeywords = newNum;
			keywords = newData;

			free(oldData);

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
		if (keywords) {
			for (std::uint32_t i = 0; i < numKeywords; ++i) {
				if (keywords[i] == a_keyword) {
					return i;
				}
			}
		}
		return std::nullopt;
	}

	std::uint32_t BGSKeywordForm::GetNumKeywords() const
	{
		return numKeywords;
	}

	bool BGSKeywordForm::RemoveKeyword(std::uint32_t a_index)
	{
		std::vector<BGSKeyword*> copiedData{ keywords, keywords + numKeywords };
		copiedData.erase(copiedData.cbegin() + a_index);

		auto newNum = static_cast<std::uint32_t>(copiedData.size());
		auto newData = calloc<BGSKeyword*>(newNum);
		std::ranges::copy(copiedData, newData);

		auto oldData = keywords;

		numKeywords = newNum;
		keywords = newData;

		free(oldData);

		return true;
	}

	bool BGSKeywordForm::RemoveKeyword(BGSKeyword* a_keyword)
	{
		auto index = GetKeywordIndex(a_keyword);
		return index ? RemoveKeyword(*index) : false;
	}
}
