#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/M/MagicSystem.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESObjectREFR.h"

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
			std::uint64_t                 unk00;     // 00
			std::uint64_t                 unk08;     // 08
			std::uint64_t                 unk10;     // 10
			ObjectRefHandle               collidee;  // 18
			NiPointer<bhkCollisionObject> colObj;    // 20
			std::uint64_t                 unk28;     // 28
			std::uint64_t                 unk30;     // 30
			std::uint64_t                 unk38;     // 38
			std::uint64_t                 unk40;     // 40
			std::uint64_t                 unk48;     // 48
		};
		static_assert(sizeof(ImpactData) == 0x50);

		~Projectile() override;  // 00

		// override (TESObjectREFR)
		bool         Load(TESFile* a_mod) override;                                         // 06 - { return TESObjectREFR::Load(a_mod); }
		void         SaveGame(BGSSaveFormBuffer* a_buf) override;                           // 0E
		void         LoadGame(BGSLoadFormBuffer* a_buf) override;                           // 0F
		void         InitLoadGame(BGSLoadFormBuffer* a_buf) override;                       // 10
		void         FinishLoadGame(BGSLoadFormBuffer* a_buf) override;                     // 11
		void         Revert(BGSLoadFormBuffer* a_buf) override;                             // 12
		bool         GetAllowPromoteToPersistent() const override;                          // 47 - { return false; }
		bool         HasKeywordHelper(const BGSKeyword* a_keyword) const override;          // 48
		void         SetActorCause(ActorCause* a_cause) override;                           // 50 - { actorCause = a_cause; }
		ActorCause*  GetActorCause() const override;                                        // 51 - { return actorCause; }
		MagicCaster* GetMagicCaster(MagicSystem::CastingSource a_source) override;          // 5C
		bool         DetachHavok(NiAVObject* a_obj3D) override;                             // 65
		void         InitHavok() override;                                                  // 66
		NiAVObject*  Load3D(bool a_backgroundLoading) override;                             // 6A
		void         Set3D(NiAVObject* a_object, bool a_queue3DTasks = true) override;      // 6C
		void         MoveHavok(bool a_forceRec) override;                                   // 85 - { return; }
		void         GetLinearVelocity(NiPoint3& a_velocity) const override;                // 86
		void         Unk_8B(void) override;                                                 // 8B
		Projectile*  AsProjectile() override;                                               // 8F - { return this; }
		bool         OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;  // 90 - { return false; }

		// add
		virtual void Unk_A2(void);                   // A2 - { return 0; }
		virtual void Unk_A3(void);                   // A3 - { return 0; }
		virtual void Unk_A4(void);                   // A4 - { return 0; }
		virtual void Unk_A5(void);                   // A5 - { return 0; }
		virtual void Unk_A6(void);                   // A6 - { return 0; }
		virtual void Unk_A7(void);                   // A7 - { return 0; }
		virtual void Unk_A8(void);                   // A8 - { return; }
		virtual void Unk_A9(void);                   // A9 - { return; }
		virtual void Unk_AA(void);                   // AA
		virtual void UpdateImpl(float a_delta) = 0;  // AB
		virtual void Unk_AC(void);                   // AC
		virtual void Unk_AD(void);                   // AD
		virtual void Unk_AE(void);                   // AE - { return 0; }
		virtual void Unk_AF(void);                   // AF - { if (unk158) return 1.0; else return unk188; } - "float GetSpeed()"?
		virtual void Unk_B0(void);                   // B0 - { return 1.0; }
		virtual void Unk_B1(void);                   // B1 - { return 0; }
		virtual void Unk_B2(void);                   // B2 - { return; }
		virtual void Unk_B3(void);                   // B3
		virtual bool IsNotGeneratedForm() const;     // B4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }
		virtual void Unk_B5(void);                   // B5 - { void* var = unk40; if ((var->unk80 >> 17) & 1) return 1.0; else return var->unk84; }
		virtual void Unk_B6(void);                   // B6
		virtual void Unk_B7(void);                   // B7
		virtual void Unk_B8(void);                   // B8 - { return 1; }
		virtual void Unk_B9(void);                   // B9 - { return 0; }
		virtual void Unk_BA(void);                   // BA - { return 0; }
		virtual void Unk_BB(void);                   // BB
		virtual void Unk_BC(void);                   // BC
		virtual void Unk_BD(void);                   // BD
		virtual void Unk_BE(void);                   // BE
		virtual void Unk_BF(void);                   // BF - { return; }
		virtual void Handle3DLoaded();               // C0 - { return; }
		virtual void Unk_C1(void);                   // C1 - { return 0; }

		// members
		BSSimpleList<ImpactData*>  impacts;            // 098
		float                      unk0A8;             // 0A8
		float                      unk0AC;             // 0AC
		std::uint64_t              unk0B0;             // 0B0
		float                      unk0B8;             // 0B8
		float                      unk0BC;             // 0BC
		std::uint64_t              unk0C0;             // 0C0
		float                      unk0C8;             // 0C8
		float                      unk0CC;             // 0CC
		std::uint64_t              unk0D0;             // 0D0
		float                      unk0D8;             // 0D8
		float                      unk0DC;             // 0DC
		bhkSimpleShapePhantom*     unk0E0;             // 0E0 - smart ptr
		mutable BSSpinLock         unk0E8;             // 0E8
		NiPoint3                   unk0F0;             // 0F0
		float                      unk0FC;             // 0FC
		float                      unk100;             // 100
		float                      unk104;             // 104
		void*                      unk108;             // 108 - smart ptr
		void*                      unk110;             // 110 - smart ptr
		NiPointer<ActorCause>      actorCause;         // 118
		ObjectRefHandle            shooter;            // 120
		ObjectRefHandle            desiredTarget;      // 124
		BSSoundHandle              sndHandle;          // 128
		BSSoundHandle              sndCountdown;       // 134
		std::uint32_t*             unk140;             // 140
		InventoryEntryData*        unk148;             // 148
		BGSExplosion*              explosion;          // 150
		MagicItem*                 spell;              // 158
		MagicSystem::CastingSource castingSource;      // 160
		std::uint32_t              pad164;             // 164
		EffectSetting*             avEffect;           // 168
		NiPointer<QueuedFile>      projectileDBFiles;  // 170
		std::uint64_t              unk178;             // 178
		std::uint64_t              unk180;             // 180
		float                      unk188;             // 188
		float                      unk18C;             // 18C
		float                      range;              // 190
		std::uint32_t              unk194;             // 194
		float                      unk198;             // 198
		float                      unk19C;             // 19C
		std::uint64_t              unk1A0;             // 1A0
		std::uint64_t              unk1A8;             // 1A8
		TESObjectWEAP*             weaponSource;       // 1B0
		TESAmmo*                   ammoSource;         // 1B8
		float                      distanceMoved;      // 1C0
		std::uint32_t              unk1C4;             // 1C4
		std::uint32_t              unk1C8;             // 1C8
		std::uint32_t              flags;              // 1CC
		std::uint64_t              unk1D0;             // 1D0
	};
	static_assert(sizeof(Projectile) == 0x1E0);
}
