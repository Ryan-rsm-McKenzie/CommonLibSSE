#pragma once

#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/GFxTranslator.h"  // GFxTranslator


namespace RE
{
	class BSScaleformTranslator : public GFxTranslator
	{
	public:
		typedef BSTHashMap<wchar_t*, wchar_t*> TranslationTable;


		virtual ~BSScaleformTranslator();						// 00

		// override (GFxTranslator)
		virtual void GetTranslation(wchar_t*& a_key) override;	// 02


		// members
		TranslationTable translationTable;	// 20
	};
	STATIC_ASSERT(sizeof(BSScaleformTranslator) == 0x50);
}
