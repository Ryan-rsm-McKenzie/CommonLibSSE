#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BarrierProjectile

#include "RE/FormTypes.h"  // FormType
#include "RE/Projectile.h"  // Projectile


namespace RE
{
	class BarrierProjectile : public Projectile
	{
	public:
		inline static const void* RTTI = RTTI_BarrierProjectile;


		enum { kTypeID = FormType::ProjectileBarrier };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BarrierProjectile();									// 00

		// override (Projectile)
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	Unk_66(void) override;							// 66
		virtual void	Unk_6A(void) override;							// 6A
		virtual void	Unk_A7(void) override;							// A7 - { return 1; }
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AC(void) override;							// AC
		virtual void	Unk_B8(void) override;							// B8 - { return 0; }


		// members
		UInt64	unk1D8;	// 1D8
		UInt64	unk1E0;	// 1E0
		UInt64	unk1E8;	// 1E8
		UInt64	unk1F0;	// 1F0
	};
	STATIC_ASSERT(sizeof(BarrierProjectile) == 0x1F8);
}
