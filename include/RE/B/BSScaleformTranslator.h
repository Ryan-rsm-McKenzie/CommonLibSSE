#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/Scaleform/GFxLoader/GFxTranslator.h"


namespace RE
{
	struct BSTranslator
	{
	public:
		// members
		BSTHashMap<BSFixedStringW, BSFixedStringW> translationMap;	// 00
	};
	static_assert(sizeof(BSTranslator) == 0x30);


	class BSScaleformTranslator : public GFxTranslator
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSScaleformTranslator;


		virtual ~BSScaleformTranslator();  // 00

		// override (GFxTranslator)
		virtual void Translate(TranslateInfo* a_translateInfo) override;  // 02


		// members
		BSTranslator translator;  // 20
	};
	static_assert(sizeof(BSScaleformTranslator) == 0x50);
}
