#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTHashMap.h"
#include "RE/GFxTranslator.h"


namespace RE
{
	class BSScaleformTranslator : public GFxTranslator
	{
	public:
		inline static const void* RTTI = RTTI_BSScaleformTranslator;


		using TranslationTable = BSTHashMap<BSFixedStringW, BSFixedStringW>;


		virtual ~BSScaleformTranslator();									// 00

		// override (GFxTranslator)
		virtual void Translate(TranslateInfo* a_translateInfo) override;	// 02


		// members
		TranslationTable translationTable;	// 20
	};
	STATIC_ASSERT(sizeof(BSScaleformTranslator) == 0x50);
}
