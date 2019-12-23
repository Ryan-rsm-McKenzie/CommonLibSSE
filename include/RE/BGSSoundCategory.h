#pragma once

#include "RE/BSISoundCategory.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class BGSSoundCategory :
		public TESForm,			// 00
		public TESFullName,		// 20
		public BSISoundCategory	// 30
	{
	public:
		inline static const void* RTTI = RTTI_BGSSoundCategory;


		enum { kTypeID = FormType::SoundCategory };


		enum class Flag : UInt32	// FNAM
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


		virtual ~BGSSoundCategory();					// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13

		constexpr float	GetStaticVolumeMultiplier() const { return staticVolumeMultiplier / USHRT_MAX; }
		constexpr void	SetStaticVolumeMultiplier(float a_val) { staticVolumeMultiplier = static_cast<UInt16>(a_val * USHRT_MAX); }
		constexpr float	GetDefaultMenuValue() const { return defaultMenuValue / USHRT_MAX; }
		constexpr void	SetDefaultMenuValue(float a_val) { defaultMenuValue = static_cast<UInt16>(a_val * USHRT_MAX); }


		// members
		Flag				flags;					// 38 - FNAM
		UInt32				unk3C;					// 3C
		BGSSoundCategory*	parent;					// 40 - SNCT
		UInt16				unk48;					// 48 - flag?
		UInt16				unk4A;					// 4A
		UInt16				staticVolumeMultiplier;	// 4C - VNAM
		UInt16				defaultMenuValue;		// 4E - UNAM
		float				ingameVolume;			// 50
		float				unk54;					// 54
	};
	STATIC_ASSERT(sizeof(BGSSoundCategory) == 0x58);
}
