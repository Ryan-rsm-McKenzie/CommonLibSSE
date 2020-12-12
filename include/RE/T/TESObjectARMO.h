#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/BGSBipedObjectForm.h"
#include "RE/FormComponents/BGSBlockBashData.h"
#include "RE/FormComponents/BGSDestructibleObjectForm.h"
#include "RE/FormComponents/BGSEquipType.h"
#include "RE/FormComponents/BGSKeywordForm.h"
#include "RE/FormComponents/BGSPickupPutdownSounds.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESBipedModelForm.h"
#include "RE/FormComponents/TESDescription.h"
#include "RE/FormComponents/TESEnchantableForm.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESRaceForm.h"
#include "RE/FormComponents/TESValueForm.h"
#include "RE/FormComponents/TESWeightForm.h"


namespace RE
{
	class TESObjectARMO :
		public TESBoundObject,			   // 000
		public TESFullName,				   // 030
		public TESRaceForm,				   // 040
		public TESEnchantableForm,		   // 050
		public TESValueForm,			   // 068
		public TESWeightForm,			   // 078
		public BGSDestructibleObjectForm,  // 088
		public BGSPickupPutdownSounds,	   // 098
		public TESBipedModelForm,		   // 0B0
		public BGSEquipType,			   // 1A0
		public BGSBipedObjectForm,		   // 1B0
		public BGSBlockBashData,		   // 1C0
		public BGSKeywordForm,			   // 1D8
		public TESDescription			   // 1F0
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectARMO;
		inline static constexpr auto FORMTYPE = FormType::Armor;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kShield = 1 << 6,
				kIgnored = 1 << 12
			};
		};


		// override (TESBoundObject)
		virtual void	 InitializeData() override;					   // 04
		virtual bool	 Load(TESFile* a_mod) override;				   // 06
		virtual void	 SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void	 LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void	 InitItemImpl() override;					   // 13
		virtual TESFile* GetDescriptionOwnerFile() const override;	   // 14 - { return templateArmor ? templateArmor->GetFile(-1) : GetFile(-1); }
		virtual void	 Copy(TESForm* a_srcForm) override;			   // 2F

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		float GetArmorRating();


		// members
		std::uint32_t			 armorRating;	 // 200 - DNAM - CK value * 100 as a std::uint32_t
		std::uint32_t			 pad204;		 // 204
		BSTArray<TESObjectARMA*> armorAddons;	 // 208
		TESObjectARMO*			 templateArmor;	 // 220 - TNAM
	};
	static_assert(sizeof(TESObjectARMO) == 0x228);
}
