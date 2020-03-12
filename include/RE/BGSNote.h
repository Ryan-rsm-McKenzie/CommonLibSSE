#pragma once

#include "RE/BGSPickupPutdownSounds.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModel.h"


namespace RE
{
	class BGSNote :
		public TESBoundObject,		   // 00
		public TESModel,			   // 30
		public TESFullName,			   // 58
		public TESIcon,				   // 68
		public BGSPickupPutdownSounds  // 78
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSNote;
		inline static constexpr auto FORMTYPE = FormType::Note;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kNoteRead = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
			};
		};


		virtual ~BGSNote();	 // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;																													  // 04
		virtual void ClearData() override;																														  // 05
		virtual bool Load(TESFile* a_mod) override;																												  // 06
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;																								  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;																									  // 12
		virtual void InitItemImpl() override;																													  // 13
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;  // 37


		// members
		TESTopic*				unk90;	// 90
		TESActorBase*			unk98;	// 98
		BSSimpleList<TESQuest*> unkA0;	// A0
		UInt64					unkB0;	// B0
	};
	STATIC_ASSERT(sizeof(BGSNote) == 0xB8);
}
