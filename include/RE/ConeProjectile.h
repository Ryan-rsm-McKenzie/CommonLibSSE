#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ConeProjectile

#include "RE/FormTypes.h"  // FormType
#include "RE/Projectile.h"  // Projectile


namespace RE
{
	class ConeProjectile : public Projectile
	{
	public:
		inline static const void* RTTI = RTTI_ConeProjectile;


		enum { kTypeID = FormType::ProjectileCone };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~ConeProjectile();										// 00

		// override (Projectile)
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	Unk_A9(void) override;							// A9
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AC(void) override;							// AC
		virtual void	Unk_B8(void) override;							// B8 - { return 0; }
		virtual void	Unk_BC(void) override;							// BC
		virtual void	Unk_BD(void) override;							// BD
		virtual void	Unk_BE(void) override;							// BE
		virtual void	Unk_C0(void) override;							// C0

		// add
		virtual void	Unk_C2(void);									// C2 - { return 1; }


		// members
		UInt64	unk1D8;	// 1D8
		UInt64	unk1E0;	// 1E0
		UInt64	unk1E8;	// 1E8
		UInt64	unk1F0;	// 1F0
		UInt64	unk1F8;	// 1F8
		UInt64	unk200;	// 200
		UInt64	unk208;	// 208
		UInt64	unk210;	// 210
	};
	STATIC_ASSERT(sizeof(ConeProjectile) == 0x218);
}
