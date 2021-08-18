#pragma once

namespace RE
{
	class GFxWWHelper
	{
	public:
		enum class BreakInfoFlags
		{
			kNone = 0,
			kNonStartingChar = 1 << 0,
			kNonTerminatingChar = 1 << 1,
			kAll = kNonStartingChar | kNonTerminatingChar
		};

		// An enumeration that describes bits in word-wrapping mode bit mask parameter of the Translator constructor.
		enum class WordWrappingType
		{
			kNone = 0,
			kDefault = static_cast<std::underlying_type_t<WordWrappingType>>(kNone),  // - Custom word-wrapping is off, OnWordWrapping will not be invoked
			kAsian = 1 << 0,                                                          // - Turns on Chinese word-wrapping rules
			kProhibition = 1 << 1,                                                    // - Prohibits certain chars at start/end of line (turns on Japanese prohibition rule)
			kNoHangulWrap = 1 << 2,                                                   // - Turns on Korean-specific word-wrapping rules
			kCustom = 1 << 7,
			kLast = static_cast<std::underlying_type_t<WordWrappingType>>(kNoHangulWrap),
			kHyphenation = kLast < 1,
			kKorean = kProhibition | kNoHangulWrap,
			kJapanese = static_cast<std::underlying_type_t<WordWrappingType>>(kProhibition),
			kChinese = kProhibition | kAsian,
			kAll = kAsian | kProhibition | kNoHangulWrap
		};

		struct CharBreakInfo
		{
			wchar_t                                        ch;     // 0
			stl::enumeration<BreakInfoFlags, std::uint8_t> flags;  // 2
			std::uint8_t                                   pad3;   // 3
		};
		static_assert(sizeof(CharBreakInfo) == 0x4);

		static bool  FindCharWithFlags(WordWrappingType a_wwMode, wchar_t a_ch, BreakInfoFlags a_charBreakFlags);
		static bool  IsAsianChar(WordWrappingType a_wwMode, wchar_t a_ch);
		static bool  IsNonStartingChar(WordWrappingType a_wwMode, wchar_t a_ch);
		static bool  IsNonTerminatingChar(WordWrappingType a_wwMode, wchar_t a_ch);
		static bool  IsWhiteSpaceChar(wchar_t a_ch);
		static bool  IsLineFeedChar(wchar_t a_ch);
		static bool  IsLineBreakOpportunityAt(WordWrappingType a_wwMode, const wchar_t* a_wstr, UPInt a_index);
		static bool  IsLineBreakOpportunityAt(WordWrappingType a_wwMode, wchar_t a_prevChar, wchar_t a_curChar);
		static UPInt FindNextNonWhiteSpace(const wchar_t* a_wstr, UPInt a_pos, UPInt a_maxPos);
		static UPInt FindPrevNonWhiteSpace(const wchar_t* a_wstr, UPInt a_pos);
		static bool  IsVowel(wchar_t a_ch);
		static UPInt FindWordWrapPos(WordWrappingType a_wwMode, UPInt a_wordWrapPos, const wchar_t* a_paraText, UPInt a_paraLen, UPInt a_lineStartPos, UPInt a_lineLen);

		static inline CharBreakInfo charBreakInfoArray[] = {
			{ 0x2010, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2012, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2013, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2014, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2018, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x2019, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x201C, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x201D, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2024, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2025, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2026, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2027, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2032, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2033, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2035, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x20A7, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x2103, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2109, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2116, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x2212, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x2213, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x2122, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x2574, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x266F, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x3001, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3002, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3005, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3008, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x3009, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x300A, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x300B, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x300C, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x300D, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x300E, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x300F, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3010, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x3011, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3012, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x3014, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x3015, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x301C, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x301D, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x301E, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x301F, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3041, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3043, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3045, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3047, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3049, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3063, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3083, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3085, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x3087, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x308E, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x309B, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x309C, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x309D, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x309E, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30A1, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30A3, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30A5, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30A7, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30A9, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30C3, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30E3, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30E5, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30E7, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30EE, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30F5, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30F6, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30FB, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30FC, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30FD, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x30FE, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FDFC, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE50, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE51, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE52, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE54, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE55, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE56, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE57, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE59, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FE5A, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE5B, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FE5C, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE5D, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FE5E, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FE6A, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF01, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF04, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FF05, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF08, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FF09, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF0C, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF0E, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF1A, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF1B, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF1F, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF20, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FF3B, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FF3D, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF5B, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FF5D, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF61, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FF64, BreakInfoFlags::kNonStartingChar, 0 },
			{ 0x0FFE0, BreakInfoFlags::kAll, 0 },
			{ 0x0FFE1, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FFE5, BreakInfoFlags::kNonTerminatingChar, 0 },
			{ 0x0FFE6, BreakInfoFlags::kNonTerminatingChar, 0 }
		};
	};
	static_assert(sizeof(GFxWWHelper) == 0x1);
}
