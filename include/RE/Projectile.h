#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Projectile

#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	class bhkSimpleShapePhantom;
	class QueuedFile;


	class Projectile : public TESObjectREFR
	{
	public:
		inline static const void* RTTI = RTTI_Projectile;


		virtual ~Projectile();													// 00

		// override (TESObjectREFR)
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void			Unk_10(void) override;							// 10
		virtual void			Unk_11(void) override;							// 11
		virtual void			Unk_12(void) override;							// 12
		virtual void			Unk_47(void) override;							// 47 - { return 0; }
		virtual bool			HasKeyword(BGSKeyword* a_keyword) override;		// 48
		virtual void			SetActorCause(void* a_cause) override;			// 50
		virtual void*			GetActorCause() const override;					// 51 - { return unk118; }
		virtual MagicCaster*	GetMagicCaster(UInt32 a_slot) const override;	// 5C
		virtual void			Unk_65(void) override;							// 65
		virtual void			Unk_66(void) override;							// 66
		virtual void			Unk_6A(void) override;							// 6A
		virtual void			Unk_6C(void) override;							// 6C
		virtual void			Unk_85(void) override;							// 85 - { return; }
		virtual void			Unk_86(void) override;							// 86
		virtual void			Unk_8B(void) override;							// 8B
		virtual void			Unk_8F(void) override;							// 8F - { return this; }
		virtual void			Unk_90(void) override;							// 90 - { return 0; }

		// add
		virtual void			Unk_A2(void);									// A2 - { return 0; }
		virtual void			Unk_A3(void);									// A3 - { return 0; }
		virtual void			Unk_A4(void);									// A4 - { return 0; }
		virtual void			Unk_A5(void);									// A5 - { return 0; }
		virtual void			Unk_A6(void);									// A6 - { return 0; }
		virtual void			Unk_A7(void);									// A7 - { return 0; }
		virtual void			Unk_A8(void);									// A8 - { return; }
		virtual void			Unk_A9(void);									// A9 - { return; }
		virtual void			Unk_AA(void);									// AA
		virtual void			Unk_AB(void) = 0;								// AB
		virtual void			Unk_AC(void);									// AC
		virtual void			Unk_AD(void);									// AD
		virtual void			Unk_AE(void);									// AE - { return 0; }
		virtual void			Unk_AF(void);									// AF - { if (unk158) return 1.0; else return unk188; } - "float GetSpeed()"?
		virtual void			Unk_B0(void);									// B0 - { return 1.0; }
		virtual void			Unk_B1(void);									// B1 - { return 0; }
		virtual void			Unk_B2(void);									// B2 - { return; }
		virtual void			Unk_B3(void);									// B3
		virtual bool			IsNotGeneratedForm() const;						// B4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }
		virtual void			Unk_B5(void);									// B5 - { void* var = unk40; if ((var->unk80 >> 17) & 1) return 1.0; else return var->unk84; }
		virtual void			Unk_B6(void);									// B6
		virtual void			Unk_B7(void);									// B7
		virtual void			Unk_B8(void);									// B8 - { return 1; }
		virtual void			Unk_B9(void);									// B9 - { return 0; }
		virtual void			Unk_BA(void);									// BA - { return 0; }
		virtual void			Unk_BB(void);									// BB
		virtual void			Unk_BC(void);									// BC
		virtual void			Unk_BD(void);									// BD
		virtual void			Unk_BE(void);									// BE
		virtual void			Unk_BF(void);									// BF - { return; }
		virtual void			Unk_C0(void);									// C0 - { return; }
		virtual void			Unk_C1(void);									// C1 - { return 0; }


		// members
		UInt64					unk098;			// 098
		UInt64					unk0A0;			// 0A0
		float					unk0A8;			// 0A8
		float					unk0AC;			// 0AC
		UInt64					unk0B0;			// 0B0
		float					unk0B8;			// 0B8
		float					unk0BC;			// 0BC
		UInt64					unk0C0;			// 0C0
		float					unk0C8;			// 0C8
		float					unk0CC;			// 0CC
		UInt64					unk0D0;			// 0D0
		float					unk0D8;			// 0D8
		float					unk0DC;			// 0DC
		bhkSimpleShapePhantom*	unk0E0;			// 0E0
		mutable BSUniqueLock	unk0E8;			// 0E8
		NiPoint3				unk0F0;			// 0F0
		float					unk0FC;			// 0FC
		float					unk100;			// 100
		float					unk104;			// 104
		UInt64					unk108;			// 108
		UInt64					unk110;			// 110
		UInt64					unk118;			// 118
		RefHandle				shooterHandle;	// 120
		UInt32					unk124;			// 124
		UInt64					unk128;			// 128
		UInt64					unk130;			// 130
		UInt64					unk138;			// 138
		UInt64					unk140;			// 140
		UInt64					unk148;			// 148
		UInt64					unk150;			// 150
		UInt64					unk158;			// 158
		UInt64					unk160;			// 160
		UInt64					unk168;			// 168
		QueuedFile*				unk170;			// 170
		UInt64					unk178;			// 178
		UInt64					unk180;			// 180
		float					unk188;			// 188
		float					unk18C;			// 18C
		float					unk190;			// 190
		UInt32					unk194;			// 194
		float					unk198;			// 198
		float					unk19C;			// 19C
		UInt64					unk1A0;			// 1A0
		UInt64					unk1A8;			// 1A8
		TESObjectWEAP*			sourceWeapon;	// 1B0
		TESAmmo*				ammo;			// 1B8
		UInt64					unk1C0;			// 1C0
		UInt64					unk1C8;			// 1C8
		UInt64					unk1D0;			// 1D0
	};
	STATIC_ASSERT(sizeof(Projectile) == 0x1D8);
}
