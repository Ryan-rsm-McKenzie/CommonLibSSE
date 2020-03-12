#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"


namespace RE
{
	class TESLoadScreen : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLoadScreen;
		inline static constexpr auto FORMTYPE = FormType::LoadScreen;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kDisplaysInMainMenu = 1 << 10,
				kIgnored = 1 << 12
			};
		};


		struct LoadNIFData
		{
			TESBoundObject* loadNIF;					   // 00 - NNAM
			float			initialScale;				   // 08 - SNAM
			SInt16			rotationConstraints[3];		   // 0C - RNAM
			SInt16			rotationOffsetConstraints[2];  // 12 - ONAM
			UInt16			pad16;						   // 16
			float			initialTranslationOffset[3];   // 18 - XNAM
			UInt32			pad24;						   // 24
			TESModel		cameraPath;					   // 28 - MOD2
		};
		STATIC_ASSERT(sizeof(LoadNIFData) == 0x50);


		virtual ~TESLoadScreen();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04 - { return; }
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		TESCondition  conditions;	// 20
		LoadNIFData*  loadNIFData;	// 28
		BSFixedString loadingText;	// 30
	};
	STATIC_ASSERT(sizeof(TESLoadScreen) == 0x38);
}
