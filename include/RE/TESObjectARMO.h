#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESEnchantableForm, TESValueForm, TESWeightForm, BGSDestructibleObjectForm, BGSPickupPutdownSounds, TESBipedModelForm, BGSEquipType, BGSBlockBashData, TESDescription

#include "RE/BGSBipedObjectForm.h"  // BGSBipedObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BSTArray.h"  // BSTArray
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESRaceForm.h"  // TESRaceForm


namespace RE
{
	class TESObjectARMO :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESRaceForm,					// 040
		public TESEnchantableForm,			// 050
		public TESValueForm,				// 068
		public TESWeightForm,				// 078
		public BGSDestructibleObjectForm,	// 088
		public BGSPickupPutdownSounds,		// 098
		public TESBipedModelForm,			// 0B0
		public BGSEquipType,				// 1A0
		public BGSBipedObjectForm,			// 1B0
		public BGSBlockBashData,			// 1C0
		public BGSKeywordForm,				// 1D8
		public TESDescription				// 1F0
	{
	public:
		enum { kTypeID = FormType::Armor };


		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitItem() override;							// 13
		virtual void	CopyFrom(TESForm* a_srcForm) override;			// 2F


		// members
		UInt32						armorValTimes100;	// 200
		UInt32						pad204;				// 204
		BSTArray<TESObjectARMA*>	armorAddons;		// 208
		TESObjectARMO*				templateArmor;		// 220 - enchantment related?
	};
	STATIC_ASSERT(offsetof(TESObjectARMO, armorValTimes100) == 0x200);
	STATIC_ASSERT(sizeof(TESObjectARMO) == 0x228);
}
