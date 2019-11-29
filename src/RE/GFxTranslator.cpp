#include "RE/GFxTranslator.h"

#include <string_view>

#include "RE/GFxWStringBuffer.h"


namespace RE
{
	GFxTranslator::TranslateInfo::TranslateInfo() :
		key(0),
		result(0),
		instanceName(0),
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
		return (flags & Flag::kResultSourceHTML) != Flag::kNone;
	}


	void GFxTranslator::TranslateInfo::SetResult(const wchar_t* a_resultText, UPInt a_resultLen)
	{
		if (a_resultLen != UPINT_MAX) {
			std::wstring_view view(a_resultText, a_resultLen);
			*result = view;
		} else {
			*result = a_resultText;
		}
		flags |= Flag::kTranslated;
	}


	void GFxTranslator::TranslateInfo::SetResultHTML(const wchar_t* a_resultHTML, UPInt a_resultLen)
	{
		SetResult(a_resultHTML, a_resultLen);
		flags |= Flag::kResultHTML;
	}


	GFxTranslator::TranslateCap GFxTranslator::GetCaps() const
	{
		return TranslateCap::kNone;
	}


	bool GFxTranslator::CanReceiveHTML() const
	{
		return (GetCaps() & TranslateCap::kReceiveHTML) != TranslateCap::kNone;
	}


	bool GFxTranslator::NeedStripNewLines() const
	{
		return (GetCaps() & TranslateCap::kStripTrailingNewLines) != TranslateCap::kNone;
	}


	bool GFxTranslator::HandlesCustomWordWrapping() const
	{
		return (wwMode != WordWrappingType::kDefault);
	}
}
