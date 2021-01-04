#pragma once

#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/S/Sexes.h"
#include "RE/T/TESModelTextureSwap.h"
#include "RE/T/TESObject.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	struct OBJ_ARMA	 // DNAM
	{
		std::int8_t	 priorities[SEXES::kTotal];	 // 0
		std::int8_t	 modelRange[SEXES::kTotal];	 // 2
		std::int8_t	 unused[SEXES::kTotal];		 // 4
		std::int8_t	 detectionSoundValue;		 // 6
		std::uint8_t pad07;						 // 7
		float		 weaponAdjust;				 // 8
	};
	static_assert(sizeof(OBJ_ARMA) == 0xC);

	class TESObjectARMA :
		public TESObject,		   // 00
		public TESRaceForm,		   // 20
		public BGSBipedObjectForm  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectARMA;
		inline static constexpr auto FORMTYPE = FormType::Armature;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~TESObjectARMA();  // 00

		// override (TESObject)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		bool IsValidRace(TESRace* a_sourceRace) const;
		void GetNodeName(char* a_dstBuff, const TESObjectREFR* a_refr, const TESObjectARMO* a_armor, float a_weightOverride);

		// members
		OBJ_ARMA			data;								  // 040 - DNAM
		std::uint32_t		pad04C;								  // 04C
		TESModelTextureSwap bipedModels[SEXES::kTotal];			  // 050
		TESModelTextureSwap bipedModel1stPersons[SEXES::kTotal];  // 0C0
		BGSTextureSet*		skinTextures[SEXES::kTotal];		  // 130 - NAM0 - NAM1
		BGSListForm*		skinTextureSwapLists[SEXES::kTotal];  // 140 - NAM2 - NAM3
		BSTArray<TESRace*>	additionalRaces;					  // 150 - MODL
		BGSFootstepSet*		footstepSet;						  // 168 - SNDD
		BGSArtObject*		artObject;							  // 170 - ONAM
	};
	static_assert(sizeof(TESObjectARMA) == 0x178);
}
