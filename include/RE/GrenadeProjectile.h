#pragma once

#include "RE/FormTypes.h"
#include "RE/Projectile.h"


namespace RE
{
	class GrenadeProjectile : public Projectile
	{
	public:
		inline static const void* RTTI = RTTI_GrenadeProjectile;


		enum { kTypeID = FormType::ProjectileGrenade };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~GrenadeProjectile();									// 00

		// override (Projectile)
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitLoadGame(void* a_arg1) override;			// 10
		virtual void	FinishLoadGame(void* a_arg1) override;			// 11
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void*	GetDecalGroup() override;						// 9F - { return unk1D8; }
		virtual void	Unk_A3(void) override;							// A3 - { return 1; }
		virtual void	Unk_A8(void) override;							// A8
		virtual void	Unk_A9(void) override;							// A9
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AE(void) override;							// AE
		virtual void	Unk_B2(void) override;							// B2
		virtual void	Unk_B3(void) override;							// B3
		virtual bool	IsNotGeneratedForm() const override;			// B4
		virtual void	Unk_BA(void) override;							// BA - { return 1; }
		virtual void	Unk_BB(void) override;							// BB
		virtual void	Unk_BD(void) override;							// BD
		virtual void	Unk_BF(void) override;							// BF - { unk1CC |= 1 << 30; }
		virtual void	Handle3DLoaded() override;						// C0


		// members
		UInt64	unk1D8;	// 1D8
		UInt64	unk1E0;	// 1E0
	};
	STATIC_ASSERT(sizeof(GrenadeProjectile) == 0x1E8);
}
