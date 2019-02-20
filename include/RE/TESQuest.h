#pragma once

#include "RE/BGSStoryManagerTreeForm.h"  // BGSStoryManagerTreeForm
#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
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


		struct LocalFlags
		{
			enum LocalFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESQuest();												// 00

		// override (BGSStoryManagerTreeForm)
		virtual void		InitDefaults() override;						// 04
		virtual bool		LoadForm(TESFile* a_mod) override;				// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void		InitItem() override;							// 13
		virtual const char*	GetEditorID() override;							// 32 - { return editorID.c_str() ? editorID.c_str() : ""; }
		virtual bool		SetEditorID(const char* a_str) override;		// 33


		// members
		BSTArray<void*>					unk038;		// 038
		UInt64							unk050;		// 050
		BSTArray<BGSBaseAlias*>			aliases;	// 058
		BSTHashMap<UnkKey, UnkValue>	unk070;		// 070
		BSTHashMap<UnkKey, UnkValue>	unk0A0;		// 0A0
		UInt64							unk0D0;		// 0D0
		UInt64							unk0D8;		// 0D8
		UInt64							unk0E0;		// 0E0
		UInt64							unk0E8;		// 0E8
		UInt64							unk0F0;		// 0F0
		UInt64							unk0F8;		// 0F8
		UInt64							unk100;		// 100
		UInt64							unk108;		// 108
		UInt64							unk110;		// 110
		BSTHashMap<UnkKey, UnkValue>	unk118;		// 118
		BSTHashMap<UnkKey, UnkValue>	unk148;		// 148
		BSTArray<void*>					unk178[6];	// 178
		UInt64							unk208;		// 208
		UInt64							unk210;		// 210
		UInt64							unk218;		// 218
		BSTArray<void*>*				unk220;		// 220
		UInt64							unk228;		// 228
		BSString						editorID;	// 230
		UInt64							unk240;		// 240
		UInt64							unk248;		// 248
		BSTArray<void*>					unk250;		// 250
	};
	STATIC_ASSERT(sizeof(TESQuest) == 0x268);
	// virtual UInt64 Unk_3D(); - { return unk108; }
	// virtual UInt64 Unk_3E(void* a_arg1); - { return a_arg1->Unk_03(this); }
}
