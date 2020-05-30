#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSSoundHandle.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/MagicSystem.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESObjectREFR.h"


namespace RE
{
	class bhkCollisionObject;
	class bhkSimpleShapePhantom;
	class QueuedFile;


	class Projectile : public TESObjectREFR
	{
	public:
		inline static constexpr auto RTTI = RTTI_Projectile;


		struct ImpactData
		{
		public:
			// members
			UInt64						  unk00;	 // 00
			UInt64						  unk08;	 // 08
			UInt64						  unk10;	 // 10
			ObjectRefHandle				  collidee;	 // 18
			NiPointer<bhkCollisionObject> colObj;	 // 20
			UInt64						  unk28;	 // 28
			UInt64						  unk30;	 // 30
			UInt64						  unk38;	 // 38
			UInt64						  unk40;	 // 40
			UInt64						  unk48;	 // 48
		};
		STATIC_ASSERT(sizeof(ImpactData) == 0x50);


		virtual ~Projectile();	// 00

		// override (TESObjectREFR)
		virtual bool		 Load(TESFile* a_mod) override;											// 06 - { return TESObjectREFR::Load(a_mod); }
		virtual void		 SaveGame(BGSSaveFormBuffer* a_buf) override;							// 0E
		virtual void		 LoadGame(BGSLoadFormBuffer* a_buf) override;							// 0F
		virtual void		 InitLoadGame(BGSLoadFormBuffer* a_buf) override;						// 10
		virtual void		 FinishLoadGame(BGSLoadFormBuffer* a_buf) override;						// 11
		virtual void		 Revert(BGSLoadFormBuffer* a_buf) override;								// 12
		virtual bool		 GetAllowPromoteToPersistent() const override;							// 47 - { return false; }
		virtual bool		 HasKeywordHelper(const BGSKeyword* a_keyword) const override;			// 48
		virtual void		 SetActorCause(ActorCause* a_cause) override;							// 50 - { actorCause = a_cause; }
		virtual ActorCause*	 GetActorCause() const override;										// 51 - { return actorCause; }
		virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource a_source) override;			// 5C
		virtual bool		 DetachHavok(NiAVObject* a_obj3D) override;								// 65
		virtual void		 InitHavok() override;													// 66
		virtual NiAVObject*	 Load3D(bool a_backgroundLoading) override;								// 6A
		virtual void		 Set3D(NiAVObject* a_object, bool a_queue3DTasks = true) override;		// 6C
		virtual void		 MoveHavok(bool a_forceRec) override;									// 85 - { return; }
		virtual void		 GetLinearVelocity(NiPoint3& a_velocity) const override;				// 86
		virtual void		 Unk_8B(void) override;													// 8B
		virtual Projectile*	 AsProjectile() override;												// 8F - { return this; }
		virtual bool		 OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;	// 90 - { return false; }

		// add
		virtual void Unk_A2(void);					 // A2 - { return 0; }
		virtual void Unk_A3(void);					 // A3 - { return 0; }
		virtual void Unk_A4(void);					 // A4 - { return 0; }
		virtual void Unk_A5(void);					 // A5 - { return 0; }
		virtual void Unk_A6(void);					 // A6 - { return 0; }
		virtual void Unk_A7(void);					 // A7 - { return 0; }
		virtual void Unk_A8(void);					 // A8 - { return; }
		virtual void Unk_A9(void);					 // A9 - { return; }
		virtual void Unk_AA(void);					 // AA
		virtual void UpdateImpl(float a_delta) = 0;	 // AB
		virtual void Unk_AC(void);					 // AC
		virtual void Unk_AD(void);					 // AD
		virtual void Unk_AE(void);					 // AE - { return 0; }
		virtual void Unk_AF(void);					 // AF - { if (unk158) return 1.0; else return unk188; } - "float GetSpeed()"?
		virtual void Unk_B0(void);					 // B0 - { return 1.0; }
		virtual void Unk_B1(void);					 // B1 - { return 0; }
		virtual void Unk_B2(void);					 // B2 - { return; }
		virtual void Unk_B3(void);					 // B3
		virtual bool IsNotGeneratedForm() const;	 // B4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }
		virtual void Unk_B5(void);					 // B5 - { void* var = unk40; if ((var->unk80 >> 17) & 1) return 1.0; else return var->unk84; }
		virtual void Unk_B6(void);					 // B6
		virtual void Unk_B7(void);					 // B7
		virtual void Unk_B8(void);					 // B8 - { return 1; }
		virtual void Unk_B9(void);					 // B9 - { return 0; }
		virtual void Unk_BA(void);					 // BA - { return 0; }
		virtual void Unk_BB(void);					 // BB
		virtual void Unk_BC(void);					 // BC
		virtual void Unk_BD(void);					 // BD
		virtual void Unk_BE(void);					 // BE
		virtual void Unk_BF(void);					 // BF - { return; }
		virtual void Handle3DLoaded();				 // C0 - { return; }
		virtual void Unk_C1(void);					 // C1 - { return 0; }


		// members
		BSSimpleList<ImpactData*>  impacts;			   // 098
		float					   unk0A8;			   // 0A8
		float					   unk0AC;			   // 0AC
		UInt64					   unk0B0;			   // 0B0
		float					   unk0B8;			   // 0B8
		float					   unk0BC;			   // 0BC
		UInt64					   unk0C0;			   // 0C0
		float					   unk0C8;			   // 0C8
		float					   unk0CC;			   // 0CC
		UInt64					   unk0D0;			   // 0D0
		float					   unk0D8;			   // 0D8
		float					   unk0DC;			   // 0DC
		bhkSimpleShapePhantom*	   unk0E0;			   // 0E0 - smart ptr
		mutable BSSpinLock		   unk0E8;			   // 0E8
		NiPoint3				   unk0F0;			   // 0F0
		float					   unk0FC;			   // 0FC
		float					   unk100;			   // 100
		float					   unk104;			   // 104
		void*					   unk108;			   // 108 - smart ptr
		void*					   unk110;			   // 110 - smart ptr
		NiPointer<ActorCause>	   actorCause;		   // 118
		ObjectRefHandle			   shooter;			   // 120
		ObjectRefHandle			   desiredTarget;	   // 124
		BSSoundHandle			   sndHandle;		   // 128
		BSSoundHandle			   sndCountdown;	   // 134
		UInt32*					   unk140;			   // 140
		InventoryEntryData*		   unk148;			   // 148
		BGSExplosion*			   explosion;		   // 150
		MagicItem*				   spell;			   // 158
		MagicSystem::CastingSource castingSource;	   // 160
		UInt32					   pad164;			   // 164
		EffectSetting*			   avEffect;		   // 168
		NiPointer<QueuedFile>	   projectileDBFiles;  // 170
		UInt64					   unk178;			   // 178
		UInt64					   unk180;			   // 180
		float					   unk188;			   // 188
		float					   unk18C;			   // 18C
		float					   range;			   // 190
		UInt32					   unk194;			   // 194
		float					   unk198;			   // 198
		float					   unk19C;			   // 19C
		UInt64					   unk1A0;			   // 1A0
		UInt64					   unk1A8;			   // 1A8
		TESObjectWEAP*			   weaponSource;	   // 1B0
		TESAmmo*				   ammoSource;		   // 1B8
		float					   distanceMoved;	   // 1C0
		UInt32					   unk1C4;			   // 1C4
		UInt32					   unk1C8;			   // 1C8
		UInt32					   flags;			   // 1CC
		UInt64					   unk1D0;			   // 1D0
	};
	STATIC_ASSERT(sizeof(Projectile) == 0x1D8);
}
