#pragma once

#include "RE/FormComponents/BGSDestructibleObjectForm.h"
#include "RE/FormComponents/BGSKeywordForm.h"
#include "RE/FormComponents/BGSMessageIcon.h"
#include "RE/FormComponents/BGSPickupPutdownSounds.h"
#include "RE/FormComponents/Enums/ActorValues.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESDescription.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESModel/TESModelTextureSwap.h"
#include "RE/FormComponents/TESTexture/TESIcon.h"
#include "RE/FormComponents/TESValueForm.h"
#include "RE/FormComponents/TESWeightForm.h"


namespace RE
{
	struct OBJ_BOOK	 // DATA
	{
		enum class Flag
		{
			kNone = 0,
			kAdvancesActorValue = 1 << 0,
			kCantTake = 1 << 1,
			kTeachesSpell = 1 << 2,	 // takes priority over skill
			kHasBeenRead = 1 << 3
		};


		enum class Type
		{
			kBookTome = 0x00,
			kNoteScroll = static_cast<std::underlying_type_t<Type>>(-1),
		};


		union Teaches
		{
			ActorValue actorValueToAdvance;
			SpellItem* spell;
		};
		static_assert(sizeof(Teaches) == 0x8);


		Flag GetSanitizedType() const;


		// members
		stl::enumeration<Flag, std::uint8_t> flags;	   // 00
		stl::enumeration<Type, std::uint8_t> type;	   // 01
		std::uint16_t						 pad02;	   // 02
		std::uint32_t						 pad04;	   // 04
		Teaches								 teaches;  // 08
	};
	static_assert(sizeof(OBJ_BOOK) == 0x10);


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
			enum ChangeFlag : std::uint32_t
			{
				kTeachesSkill = 1 << 5,
				kRead = 1 << 6
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~TESObjectBOOK();  // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;																																   // 04
		virtual void ClearData() override;																																	   // 05 - { return TESForm::ClearData(); }
		virtual bool Load(TESFile* a_mod) override;																															   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;																											   // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;																											   // 0F
		virtual void InitItemImpl() override;																																   // 13
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																					   // 4D

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
	static_assert(sizeof(TESObjectBOOK) == 0x138);
}
