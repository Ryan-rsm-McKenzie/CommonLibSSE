#pragma once

#include "RE/FormTypes.h"
#include "RE/Projectile.h"


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
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitLoadGame(void* a_arg1) override;			// 10
		virtual void	FinishLoadGame(void* a_arg1) override;			// 11
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	InitHavok() override;							// 66
		virtual void	Load3D(bool a_arg1) override;					// 6A
		virtual void	Unk_A7(void) override;							// A7 - { return 1; }
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AC(void) override;							// AC
		virtual void	Unk_B8(void) override;							// B8 - { return 0; }


		// members
		UInt64			unk1D8;	// 1D8
		BSTArray<void*>	unk1E0;	// 1E0
	};
	STATIC_ASSERT(sizeof(BarrierProjectile) == 0x1F8);
}
