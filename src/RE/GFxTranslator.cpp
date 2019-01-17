#include "RE/GFxTranslator.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "RE/Offsets.h"


namespace RE
{
	const wchar_t* GFxTranslator::TranslateInfo::GetKey() const
	{
		return key;
	}


	void GFxTranslator::TranslateInfo::SetResult(const wchar_t* a_resultText, UPInt a_resultLen)
	{
		typedef void _SetResult_t(TranslateInfo* a_this, const wchar_t* a_resultText, UPInt a_resultLen);
		RelocAddr<_SetResult_t*> _SetResult(GFX_TRANSLATOR_TRANSLATE_INFO_SET_RESULTW);
		_SetResult(this, a_resultText, a_resultLen);
	}
}
