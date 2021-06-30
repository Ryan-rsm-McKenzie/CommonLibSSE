#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/G/GFxTranslator.h"

namespace RE
{
	struct BSTranslator
	{
	public:
		// members
		BSTHashMap<BSFixedStringW, BSFixedStringW> translationMap;  // 00
	};
	static_assert(sizeof(BSTranslator) == 0x30);

	class BSScaleformTranslator : public GFxTranslator
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSScaleformTranslator;

		~BSScaleformTranslator() override;  // 00

		// override (GFxTranslator)
		void Translate(TranslateInfo* a_translateInfo) override;  // 02

		// members
		BSTranslator translator;  // 20
	};
	static_assert(sizeof(BSScaleformTranslator) == 0x50);
}
