#include "RE/G/GFxTranslator.h"

#include "RE/G/GFxWStringBuffer.h"

namespace RE
{
	GFxTranslator::TranslateInfo::TranslateInfo() :
		key(nullptr),
		result(nullptr),
		instanceName(nullptr),
		flags(Flag::kNone),
		pad19(0),
		pad1A(0),
		pad1C(0)
	{}

	const char* GFxTranslator::TranslateInfo::GetInstanceName() const
	{
		return instanceName;
	}

	const wchar_t* GFxTranslator::TranslateInfo::GetKey() const
	{
		return key;
	}

	bool GFxTranslator::TranslateInfo::IsKeyHTML() const
	{
		return flags.all(Flag::kResultSourceHTML);
	}

	void GFxTranslator::TranslateInfo::SetResult(const wchar_t* a_resultText, UPInt a_resultLen)
	{
		if (!a_resultText) {
			return;
		}

		if (a_resultLen != UPINT_MAX) {
			std::wstring_view view(a_resultText, a_resultLen);
			*result = view;
		} else {
			*result = a_resultText;
		}
		flags.set(Flag::kTranslated);
	}

	void GFxTranslator::TranslateInfo::SetResultHTML(const wchar_t* a_resultHTML, UPInt a_resultLen)
	{
		SetResult(a_resultHTML, a_resultLen);
		flags.set(Flag::kResultHTML);
	}

	GFxTranslator::GFxTranslator() :
		GFxState(StateType::kTranslator),
		wwMode(WordWrappingType::kDefault),
		pad1C(0)
	{}

	GFxTranslator::GFxTranslator(WordWrappingType a_wwMode) :
		GFxState(StateType::kTranslator),
		wwMode(a_wwMode),
		pad1C(0)
	{}

	auto GFxTranslator::GetCaps() const
		-> TranslateCap
	{
		return TranslateCap::kNone;
	}

	void GFxTranslator::Translate(TranslateInfo*)
	{
		return;
	}

	bool GFxTranslator::OnWordWrapping(LineFormatDesc* a_desc)
	{
		if (!HandlesCustomWordWrapping()) {
			return false;
		}

		if (wwMode.all(WordWrappingType::kAll) && a_desc->numCharsInLine > 0) {
			auto pos = GFxWWHelper::FindWordWrapPos(*wwMode, a_desc->proposedWordWrapPoint, a_desc->paraText, a_desc->paraTextLen, a_desc->lineStartPos, a_desc->numCharsInLine);
			if (pos == UPINT_MAX) {
				return false;
			}
			a_desc->proposedWordWrapPoint = pos;
			return true;
		} else {
			return false;
#if 0
			if ((wwMode & WordWrappingType::kCustom) == WordWrappingType::kNone || a_desc->proposedWordWrapPoint == 0) {
				return false;
			}

			auto pos = a_desc->proposedWordWrapPoint;
#endif
		}
	}

	bool GFxTranslator::CanReceiveHTML() const
	{
		return (stl::enumeration{ GetCaps() } & TranslateCap::kReceiveHTML) != TranslateCap::kNone;
	}

	bool GFxTranslator::NeedStripNewLines() const
	{
		return (stl::enumeration{ GetCaps() } & TranslateCap::kStripTrailingNewLines) != TranslateCap::kNone;
	}

	bool GFxTranslator::HandlesCustomWordWrapping() const
	{
		return wwMode != WordWrappingType::kDefault;
	}
}
