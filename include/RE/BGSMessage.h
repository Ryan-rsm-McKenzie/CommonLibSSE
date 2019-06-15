#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMessage

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class BGSMessage :
		public TESForm,			// 00
		public TESFullName,		// 20
		public TESDescription	// 30
	{
	public:
		inline static const void* RTTI = RTTI_BGSMessage;


		enum { kTypeID = FormType::Message };


		enum class Flag : UInt32
		{
			kNone = 0,
			kMessageBox = 1 << 0,
			kAutoDisplay = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct MenuButton
		{
			BSFixedString	buttonText;	// 00 - ITXT
			Condition		conditions;	// 08
		};
		STATIC_ASSERT(sizeof(MenuButton) == 0x10);


		virtual ~BGSMessage();								// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BGSMenuIcon*				icon;			// 40 - INAM
		TESQuest*					ownerQuest;		// 48 - QNAM
		BSSimpleList<MenuButton*>	menuButtons;	// 50
		Flag						flags;			// 60 - DNAM
		UInt32						displayTime;	// 64 - TNAM
	};
	STATIC_ASSERT(sizeof(BGSMessage) == 0x68);
}
