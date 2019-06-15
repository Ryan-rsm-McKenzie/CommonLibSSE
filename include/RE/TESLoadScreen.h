#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESLoadScreen

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class TESLoadScreen : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESLoadScreen;


		enum { kTypeID = FormType::LoadScreen };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kDisplaysInMainMenu = 1 << 10,
				kIgnored = 1 << 12
			};
		};


		struct Data
		{
			struct InitialRotation	// RNAM
			{
				SInt16	x;	// 0
				SInt16	y;	// 2
				SInt16	z;	// 4
			};
			STATIC_ASSERT(sizeof(InitialRotation) == 0x6);


			struct RotationOffsetConstraints	// ONAM
			{
				SInt16	min;	// 0
				SInt16	max;	// 2
			};
			STATIC_ASSERT(sizeof(RotationOffsetConstraints) == 0x4);


			struct InitialTranslationOffset
			{
				float	x;		// 00
				float	y;		// 04
				float	z;		// 08
				UInt32	pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(InitialTranslationOffset) == 0x10);


			TESObjectSTAT*				loadingScreenNIF;			// 00 - NNAM
			float						initialScale;				// 08 - SNAM
			InitialRotation				initialRotation;			// 0C - RNAM
			RotationOffsetConstraints	rotationOffsetConstraints;	// 12 - ONAM
			UInt16						pad16;						// 16
			InitialTranslationOffset	initialTranslationOffset;	// 18 - XNAM
			TESModel					cameraPath;					// 28 - MOD2
		};
		STATIC_ASSERT(sizeof(Data) == 0x50);


		virtual ~TESLoadScreen();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04 - { return; }
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Condition		conditions;		// 20
		Data*			data;			// 28
		BSFixedString	description;	// 30
	};
	STATIC_ASSERT(sizeof(TESLoadScreen) == 0x38);
}
