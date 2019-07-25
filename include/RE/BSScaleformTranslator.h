#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScaleformTranslator

#include "RE/BSFixedString.h"  // BSFixedStringW
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/GFxTranslator.h"  // GFxTranslator


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
