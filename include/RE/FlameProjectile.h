#pragma once

#include "RE/FormTypes.h"
#include "RE/Projectile.h"


namespace RE
{
	class FlameProjectile : public Projectile
	{
	public:
		inline static const void* RTTI = RTTI_FlameProjectile;


		enum { kTypeID = FormType::ProjectileFlame };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~FlameProjectile();										// 00

		// override (Projectile)
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitLoadGame(void* a_arg1) override;			// 10
		virtual void	FinishLoadGame(void* a_arg1) override;			// 11
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	Unk_A4(void) override;							// A4 - { return 1; }
		virtual void	Unk_A9(void) override;							// A9
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_B7(void) override;							// B7
		virtual void	Unk_BD(void) override;							// BD
		virtual void	Unk_C0(void) override;							// C0 - { unk1CC = unk1CC & 0xFFFFFFCC | 8; }
		virtual void	Unk_C1(void) override;							// C1


		// members
		UInt64 unk1D8;	// 1D8
	};
	STATIC_ASSERT(sizeof(FlameProjectile) == 0x1E0);
}
