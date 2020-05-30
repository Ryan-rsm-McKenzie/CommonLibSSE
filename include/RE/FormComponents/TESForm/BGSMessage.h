#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESDescription.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class BGSMessage :
		public TESForm,		   // 00
		public TESFullName,	   // 20
		public TESDescription  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMessage;
		inline static constexpr auto FORMTYPE = FormType::Message;


		enum class MessageFlag : UInt32
		{
			kNone = 0,
			kMessageBox = 1 << 0,
			kInitialDelay = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct MESSAGEBOX_BUTTON
		{
			BSFixedString text;		   // 00 - ITXT
			TESCondition  conditions;  // 08
		};
		STATIC_ASSERT(sizeof(MESSAGEBOX_BUTTON) == 0x10);


		virtual ~BGSMessage();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSMenuIcon*					 icon;		   // 40 - INAM
		TESQuest*						 ownerQuest;   // 48 - QNAM
		BSSimpleList<MESSAGEBOX_BUTTON*> menuButtons;  // 50
		MessageFlag						 flags;		   // 60 - DNAM
		UInt32							 displayTime;  // 64 - TNAM
	};
	STATIC_ASSERT(sizeof(BGSMessage) == 0x68);
}
