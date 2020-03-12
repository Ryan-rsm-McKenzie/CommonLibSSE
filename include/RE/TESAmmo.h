#pragma once

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
	struct AMMO_DATA  // DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kIgnoresNormalWeaponResistance = 1 << 0,
			kNonPlayable = 1 << 1,
			kNonBolt = 1 << 2
		};


		BGSProjectile* projectile;	// 00
		Flag		   flags;		// 08
		UInt8		   pa09;		// 09
		UInt16		   pa0A;		// 0A
		float		   damage;		// 0C
	};
	STATIC_ASSERT(sizeof(AMMO_DATA) == 0x10);


	class TESAmmo :
		public TESBoundObject,			   // 000
		public TESFullName,				   // 030
		public TESModelTextureSwap,		   // 040
		public TESIcon,					   // 078
		public BGSMessageIcon,			   // 088
		public TESValueForm,			   // 0A0
		public TESWeightForm,			   // 0B0
		public BGSDestructibleObjectForm,  // 0C0
		public BGSPickupPutdownSounds,	   // 0D0
		public TESDescription,			   // 0E8
		public BGSKeywordForm			   // 0F8
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESAmmo;
		inline static constexpr auto FORMTYPE = FormType::Ammo;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESAmmo();	 // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;											 // 04
		virtual bool		Load(TESFile* a_mod) override;										 // 06
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;						 // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;						 // 0F
		virtual void		InitItemImpl() override;											 // 13
		virtual bool		GetPlayable() const override;										 // 19 - { return ~((data.flags >> 1) & 1); }
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;				 // 40
		virtual void		HandleRemoveItemFromContainer(TESObjectREFR* a_container) override;	 // 4E

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		bool IgnoresNormalWeaponResistance();
		bool IsBolt();


		// members
		AMMO_DATA	  data;		  // 110 - DATA
		BSFixedString shortDesc;  // 120 - ONAM
	};
	STATIC_ASSERT(sizeof(TESAmmo) == 0x128);
}
