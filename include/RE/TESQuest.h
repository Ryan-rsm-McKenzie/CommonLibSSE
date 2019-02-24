#pragma once

#include "RE/BGSStoryManagerTreeForm.h"  // BGSStoryManagerTreeForm
#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class BGSBaseAlias;


	class TESQuest :
		public BGSStoryManagerTreeForm,	// 000
		public TESFullName				// 028
	{
	public:
		enum { kTypeID = FormType::Quest };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct General	// DNAM
		{
			enum class Flag : UInt16
			{
				kNone = 0,
				kStartGameEnabled = 1 << 0,
				kAllowRepeatedStages = 1 << 3,
				kRunOnce = 1 << 8,
				kExcludesFromDialogueExport = 1 << 9,
				kWarnOnAliasFillFailure = 1 << 10
			};


			enum class Type
			{
				kNone = 0,
				kMainQuest = 1,
				kMagesGuild = 2,
				kThievesGuild = 3,
				kDarkBrotherhood = 4,
				kCompanionsQuest = 5,
				kMiscellaneous = 6,
				kDaedric = 7,
				kSideQuest = 8,
				kCivilWar = 9,
				kDLC01_Vampire = 10,
				kDLC02_Dragonborn = 11
			};


			UInt32	unk0;	// 0
			Flag	flags;	// 4
			UInt16	unk6;	// 6
		};
		STATIC_ASSERT(sizeof(General) == 0x8);


		struct Stage
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kStartUpStage = 1 << 1,
				kShutDownStage = 1 << 2,
				kKeepInstanceDataFromHereOn = 1 << 3
			};


			UInt16	index;	// 0
			Flag	flags;	// 2
			UInt8	unk3;	// 3
			UInt32	pad4;	// 4
		};
		STATIC_ASSERT(sizeof(Stage) == 0x8);


		virtual ~TESQuest();												// 00

		// override (BGSStoryManagerTreeForm)
		virtual void		InitDefaults() override;						// 04
		virtual void		Unk_05(void) override;							// 05
		virtual bool		LoadForm(TESFile* a_mod) override;				// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void		Unk_11(void) override;							// 11
		virtual void		Unk_12(void) override;							// 12
		virtual void		InitItem() override;							// 13
		virtual const char*	GetEditorID() override;							// 32 - { return editorID.c_str() ? editorID.c_str() : ""; }
		virtual bool		SetEditorID(const char* a_str) override;		// 33
		virtual Condition*	GetConditions() override;						// 3D - { return &dialogueConditions; }
		virtual void		Unk_3E(void) override;							// 3E


		// members
		BSTArray<void*>					unk038;				// 038
		UInt64							unk050;				// 050
		BSTArray<BGSBaseAlias*>			aliases;			// 058
		BSTHashMap<UnkKey, UnkValue>	unk070;				// 070
		BSTHashMap<UnkKey, UnkValue>	unk0A0;				// 0A0
		UInt64							unk0D0;				// 0D0
		General							general;			// 0D8 - DNAM
		UInt64							unk0E0;				// 0E0
		BSSimpleList<Stage>*			executedStages;		// 0E8
		BSSimpleList<Stage*>*			waitingStages;		// 0F0
		UInt64							unk0F8;				// 0F8
		UInt64							unk100;				// 100
		Condition						dialogueConditions;	// 108
		UInt64							unk110;				// 110
		BSTHashMap<UnkKey, UnkValue>	unk118;				// 118
		BSTHashMap<UnkKey, UnkValue>	unk148;				// 148
		BSTArray<void*>					unk178;				// 178
		BSTArray<TESTopic*>				topics;				// 190
		BSTArray<void*>					unk1A8;				// 1A8
		BSTArray<void*>					unk1C0;				// 1C0
		BSTArray<void*>					unk1D8;				// 1D8
		BSTArray<void*>					unk1F0;				// 1F0
		UInt64							unk208;				// 208
		UInt64							unk210;				// 210
		UInt64							unk218;				// 218
		BSTArray<void*>*				unk220;				// 220
		UInt64							unk228;				// 228
		BSString						editorID;			// 230
		UInt64							unk240;				// 240
		UInt64							unk248;				// 248
		BSTArray<void*>					unk250;				// 250
	};
	STATIC_ASSERT(sizeof(TESQuest) == 0x268);
}
