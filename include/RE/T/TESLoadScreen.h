#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESLoadScreen : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLoadScreen;
		inline static constexpr auto VTABLE = VTABLE_TESLoadScreen;
		inline static constexpr auto FORMTYPE = FormType::LoadScreen;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kDisplaysInMainMenu = 1 << 10,
				kIgnored = 1 << 12
			};
		};

		struct LoadNIFData
		{
			TESBoundObject* loadNIF;                       // 00 - NNAM
			float           initialScale;                  // 08 - SNAM
			std::int16_t    rotationConstraints[3];        // 0C - RNAM
			std::int16_t    rotationOffsetConstraints[2];  // 12 - ONAM
			std::uint16_t   pad16;                         // 16
			float           initialTranslationOffset[3];   // 18 - XNAM
			std::uint32_t   pad24;                         // 24
			TESModel        cameraPath;                    // 28 - MOD2
		};
		static_assert(sizeof(LoadNIFData) == 0x50);

		~TESLoadScreen() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04 - { return; }
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		TESCondition  conditions;   // 20
		LoadNIFData*  loadNIFData;  // 28
		BSFixedString loadingText;  // 30
	};
	static_assert(sizeof(TESLoadScreen) == 0x38);
}
