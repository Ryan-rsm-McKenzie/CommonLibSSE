#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ArrowProjectile

#include "RE/FormTypes.h"  // FormType
#include "RE/MissileProjectile.h"  // MissileProjectile


namespace RE
{
	class ArrowProjectile : public MissileProjectile
	{
	public:
		inline static const void* RTTI = RTTI_ArrowProjectile;


		enum { kTypeID = FormType::ProjectileArrow };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~ArrowProjectile();										// 00

		// override (MissileProjectile)
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_AA(void) override;							// AA
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AC(void) override;							// AC
		virtual void	Unk_AD(void) override;							// AD
		virtual void	Unk_AF(void) override;							// AF
		virtual void	Unk_B0(void) override;							// B0
		virtual void	Unk_B1(void) override;							// B1 - { return 1; }
		virtual void	Unk_B5(void) override;							// B5
		virtual void	Unk_B9(void) override;							// B9 - { return (unk1CC >> 22) & 1; }
		virtual void	Unk_BD(void) override;							// BD
		virtual void	Unk_C0(void) override;							// C0
		virtual void	Unk_C2(void) override;							// C2 - { return 1; }
		virtual void	Unk_C3(void) override;							// C3 - { return 1; }


		// members
		UInt64	unk1E0;	// 1E0
		UInt64	unk1E8;	// 1E8
	};
	STATIC_ASSERT(sizeof(ArrowProjectile) == 0x1F0);
}
