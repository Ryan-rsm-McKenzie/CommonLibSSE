#include "RE/G/GFxWWHelper.h"

#include "RE/G/GStd.h"

namespace RE
{
	bool GFxWWHelper::FindCharWithFlags(WordWrappingType a_wwMode, wchar_t a_ch, BreakInfoFlags a_charBreakFlags)
	{
		const stl::enumeration wwMode{ a_wwMode };
		if ((wwMode & WordWrappingType::kProhibition) == WordWrappingType::kNone) {
			return false;
		}

		CharBreakInfo key;
		key.ch = a_ch;

		constexpr auto SIZE = std::extent<decltype(charBreakInfoArray)>::value;
		auto           endIt = charBreakInfoArray + SIZE;
		auto           it = std::lower_bound(charBreakInfoArray, endIt, key, [](const CharBreakInfo& a_lhs, const CharBreakInfo& a_rhs) -> bool {
            return a_lhs.ch < a_rhs.ch;
        });

		if (it == endIt || a_ch < it->ch) {
			return false;
		}

		return it->flags.all(a_charBreakFlags);
	}

	bool GFxWWHelper::IsAsianChar(WordWrappingType a_wwMode, wchar_t a_ch)
	{
		const stl::enumeration wwMode{ a_wwMode };
		if ((wwMode & WordWrappingType::kNoHangulWrap) != WordWrappingType::kNone) {
			if ((a_ch >= 0x1100 && a_ch <= 0x11FF) || (a_ch >= 0x3130 && a_ch <= 0x318F) || (a_ch >= 0xAC00 && a_ch <= 0xD7A3)) {
				return false;
			}
		}

		return (a_ch >= 0x1100 && a_ch <= 0x11FF) || (a_ch >= 0x3000 && a_ch <= 0xD7AF) || (a_ch >= 0xF900 && a_ch <= 0xFAFF) || (a_ch >= 0xFF00 && a_ch <= 0xFFDC);
	}

	bool GFxWWHelper::IsNonStartingChar(WordWrappingType a_wwMode, wchar_t a_ch)
	{
		return FindCharWithFlags(a_wwMode, a_ch, BreakInfoFlags::kNonStartingChar);
	}

	bool GFxWWHelper::IsNonTerminatingChar(WordWrappingType a_wwMode, wchar_t a_ch)
	{
		return FindCharWithFlags(a_wwMode, a_ch, BreakInfoFlags::kNonTerminatingChar);
	}

	bool GFxWWHelper::IsWhiteSpaceChar(wchar_t a_ch)
	{
		constexpr auto CHAR = static_cast<wchar_t>(0x3000);

		switch (a_ch) {
		case L'\t':
		case L'\r':
		case L' ':
		case CHAR:
			return true;
		default:
			return false;
		}
	}

	bool GFxWWHelper::IsLineFeedChar(wchar_t a_ch)
	{
		return a_ch == L'\n';
	}

	bool GFxWWHelper::IsLineBreakOpportunityAt(WordWrappingType a_wwMode, const wchar_t* a_wstr, UPInt a_index)
	{
		assert(a_wstr);
		if (a_index == 0) {
			return false;
		}

		return IsLineBreakOpportunityAt(a_wwMode, a_wstr[a_index - 1], a_wstr[a_index]);
	}

	bool GFxWWHelper::IsLineBreakOpportunityAt(WordWrappingType a_wwMode, wchar_t a_prevChar, wchar_t a_curChar)
	{
		if (a_prevChar == 0) {
			return false;
		}

		return ((IsWhiteSpaceChar(a_prevChar) || IsAsianChar(a_wwMode, a_curChar) || IsAsianChar(a_wwMode, a_prevChar) || a_prevChar == L'-')) && !IsNonStartingChar(a_wwMode, a_curChar) && !IsNonTerminatingChar(a_wwMode, a_prevChar);
	}

	UPInt GFxWWHelper::FindNextNonWhiteSpace(const wchar_t* a_wstr, UPInt a_pos, UPInt a_maxPos)
	{
		assert(a_wstr);
		while (IsWhiteSpaceChar(a_wstr[a_pos])) {
			++a_pos;
		}

		if (IsLineFeedChar(a_wstr[a_pos])) {
			++a_pos;
		}

		return a_pos <= a_maxPos ? a_pos : UPINT_MAX;
	}

	UPInt GFxWWHelper::FindPrevNonWhiteSpace(const wchar_t* a_wstr, UPInt a_pos)
	{
		assert(a_wstr);
		auto p = static_cast<SPInt>(a_pos);
		while (p >= 0 && (IsWhiteSpaceChar(a_wstr[p]) || IsLineFeedChar(a_wstr[p]))) {
			--p;
		}

		return p < 0 ? UPINT_MAX : static_cast<UPInt>(p);
	}

	bool GFxWWHelper::IsVowel(wchar_t a_ch)
	{
		switch (G_towlower(a_ch)) {
		case L'a':
		case L'e':
		case L'o':
		case L'u':
		case L'i':
			return true;
		default:
			return false;
		}
	}

	UPInt GFxWWHelper::FindWordWrapPos(WordWrappingType a_wwMode, [[maybe_unused]] UPInt a_wordWrapPos, const wchar_t* a_paraText, UPInt a_paraLen, UPInt a_lineStartPos, UPInt a_lineLen)
	{
		assert(a_paraText);

		const stl::enumeration wwMode{ a_wwMode };
		if ((wwMode & WordWrappingType::kAll) == WordWrappingType::kNone || a_lineLen == 0) {
			return UPINT_MAX;
		}

		auto       pos = a_lineLen - 1;
		const auto maxLen = a_paraLen - a_lineStartPos;
		auto       breakNow = a_lineLen == 1;
		auto       lineText = std::addressof(a_paraText[a_lineStartPos]);
		if (!breakNow) {
			do {
				if (IsWhiteSpaceChar(lineText[pos])) {
					const auto prev = FindPrevNonWhiteSpace(lineText, pos);
					if (prev == UPINT_MAX) {
						pos = FindNextNonWhiteSpace(lineText, pos + 1, maxLen - 1);
						break;
					}
					pos = prev + 1;
				}

				if (IsLineBreakOpportunityAt(*wwMode, lineText, pos)) {
					break;
				}

				--pos;
			} while (pos != 0);
			breakNow = pos == 0;
		}

		auto result = FindNextNonWhiteSpace(lineText, pos, maxLen - 1);
		if (breakNow || result == UPINT_MAX) {
			result = a_lineLen - 1;
		}
		return result;
	}
}
