#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MissileProjectile

#include "RE/FormTypes.h"  // FormType
#include "RE/Projectile.h"  // Projectile


namespace RE
{
	class MissileProjectile : public Projectile
	{
	public:
		inline static const void* RTTI = RTTI_MissileProjectile;


		enum { kTypeID = FormType::ProjectileMissile };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~MissileProjectile();									// 00

		// override (Projectile)
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_11(void) override;							// 11
		virtual void	Unk_12(void) override;							// 12
		virtual void	Unk_A2(void) override;							// A2 - { return 1; }
		virtual void	Unk_A9(void) override;							// A9
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AC(void) override;							// AC
		virtual void	Unk_B8(void) override;							// B8 - { return unk1D8 == 1; }
		virtual void	Unk_BD(void) override;							// BD
		virtual void	Unk_C0(void) override;							// C0

		// add
		virtual void	Unk_C2(void);									// C2 - { return 0; }
		virtual void	Unk_C3(void);									// C3 - { return 0; }


		// members
		UInt64 unk1D8;	// 1D8
	};
	STATIC_ASSERT(sizeof(MissileProjectile) == 0x1E0);
}
