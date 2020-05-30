#pragma once

#include "RE/BSISoundCategory.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class BGSSoundCategory :
		public TESForm,			 // 00
		public TESFullName,		 // 20
		public BSISoundCategory	 // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSoundCategory;
		inline static constexpr auto FORMTYPE = FormType::SoundCategory;


		enum class Flag : UInt32  // FNAM
		{
			kNone = 0,
			kMuteWhenSubmerged = 1 << 0,
			kShouldAppearOnMenu = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSSoundCategory();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		// override (BGSSoundCategory)
		virtual bool   Matches(const BSISoundCategory* a_category) const override;	// 01
		virtual float  GetCategoryVolume() const override;							// 02
		virtual void   SetCategoryVolume(float a_value) override;					// 03
		virtual float  GetCategoryFrequency() const override;						// 04
		virtual void   SetCategoryFrequency(float a_value) override;				// 05
		virtual UInt16 GetCategoryAttenuation() const override;						// 06
		virtual void   SetCategoryAttenuation(UInt16 a_value) override;				// 07

		float GetDefaultMenuValue() const;
		float GetStaticVolumeMultiplier() const;
		bool  IsMenuCategory() const;
		void  SetDefaultMenuValue(float a_val);
		void  SetStaticVolumeMultiplier(float a_val);


		// members
		Flag			  flags;			 // 38 - FNAM
		UInt32			  unk3C;			 // 3C
		BGSSoundCategory* parentCategory;	 // 40 - SNCT
		UInt16			  unk48;			 // 48
		UInt16			  attenuation;		 // 4A
		UInt16			  staticMult;		 // 4C - VNAM
		UInt16			  defaultMenuValue;	 // 4E - UNAM
		float			  volumeMult;		 // 50
		float			  frequencyMult;	 // 54
	};
	STATIC_ASSERT(sizeof(BGSSoundCategory) == 0x58);
}
