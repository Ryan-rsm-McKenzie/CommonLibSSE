#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESAmmo

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESAmmo :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public BGSMessageIcon,				// 088
		public TESValueForm,				// 0A0
		public TESWeightForm,				// 0B0
		public BGSDestructibleObjectForm,	// 0C0
		public BGSPickupPutdownSounds,		// 0D0
		public TESDescription,				// 0E8
		public BGSKeywordForm				// 0F8
	{
	public:
		inline static const void* RTTI = RTTI_TESAmmo;


		enum { kTypeID = FormType::Ammo };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kIgnoresNormalWeaponResistance = 1 << 0,
				kNonPlayable = 1 << 1,
				kNonBolt = 1 << 2
			};


			BGSProjectile*	projectile;	// 00
			Flag			flags;		// 08
			float			damage;		// 0C
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~TESAmmo();												// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;						// 04
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitItem() override;							// 13
		virtual bool	IsPlayable() override;							// 19 - { return ~((data.flags >> 1) & 1); }
		virtual void	Unk_40(void) override;							// 40
		virtual void	OnRemovedFrom(TESObjectREFR* a_ref) override;	// 4E

		bool			IgnoresNormalWeaponResistance();
		bool			IsBolt();


		// members
		Data			data;		// 110 - DATA
		BSFixedString	shortName;	// 120 - ONAM
	};
	STATIC_ASSERT(sizeof(TESAmmo) == 0x128);
}
