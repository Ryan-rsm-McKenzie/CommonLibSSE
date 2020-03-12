#pragma once

#include <type_traits>

#include "RE/ActorValues.h"
#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSMessageIcon.h"
#include "RE/BGSPickupPutdownSounds.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESDescription.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	struct OBJ_BOOK	 // DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kAdvancesActorValue = 1 << 0,
			kCantTake = 1 << 1,
			kTeachesSpell = 1 << 2,	 // takes priority over skill
			kHasBeenRead = 1 << 3
		};


		enum class Type : UInt8
		{
			kBookTome = 0x00,
			kNoteScroll = static_cast<std::underlying_type_t<Type>>(-1),
		};


		union Teaches
		{
			ActorValue actorValueToAdvance;
			SpellItem* spell;
		};
		STATIC_ASSERT(sizeof(Teaches) == 0x8);


		Flag GetSanitizedType() const;


		// members
		Flag	flags;	  // 00
		Type	type;	  // 01
		UInt16	pad02;	  // 02
		UInt32	pad04;	  // 04
		Teaches teaches;  // 08
	};
	STATIC_ASSERT(sizeof(OBJ_BOOK) == 0x10);


	class TESObjectBOOK :
		public TESBoundObject,			   // 00
		public TESFullName,				   // 30
		public TESModelTextureSwap,		   // 40
		public TESIcon,					   // 78
		public TESValueForm,			   // 88
		public TESWeightForm,			   // 98
		public TESDescription,			   // A8
		public BGSDestructibleObjectForm,  // B8
		public BGSMessageIcon,			   // C8
		public BGSPickupPutdownSounds,	   // E0
		public BGSKeywordForm			   // F8
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectBOOK;
		inline static constexpr auto FORMTYPE = FormType::Book;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kTeachesSkill = 1 << 5,
				kRead = 1 << 6
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~TESObjectBOOK();  // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;																													  // 04
		virtual void ClearData() override;																														  // 05 - { return TESForm::ClearData(); }
		virtual bool Load(TESFile* a_mod) override;																												  // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;																								  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;																								  // 0F
		virtual void InitItemImpl() override;																													  // 13
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;  // 37
		virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																		  // 4D

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		bool	   TeachesSkill() const;
		bool	   TeachesSpell() const;
		bool	   IsRead() const;
		bool	   CanBeTaken() const;
		bool	   IsBookTome() const;
		bool	   IsNoteScroll() const;
		ActorValue GetSkill() const;
		SpellItem* GetSpell();


		// members
		OBJ_BOOK	   data;				 // 110 - DATA
		TESObjectSTAT* inventoryModel;		 // 120 - INAM
		TESDescription itemCardDescription;	 // 128 - CNAM
	};
	STATIC_ASSERT(sizeof(TESObjectBOOK) == 0x138);
}
