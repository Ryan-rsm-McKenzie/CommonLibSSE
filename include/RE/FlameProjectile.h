#pragma once

#include "skse64/GameRTTI.h"  // RTTI_FlameProjectile

#include "RE/FormTypes.h"  // FormType
#include "RE/Projectile.h"  // Projectile


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
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
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
