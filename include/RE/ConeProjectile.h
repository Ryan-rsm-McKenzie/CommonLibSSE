#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/Projectile.h"


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
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitLoadGame(void* a_arg1) override;			// 10
		virtual void	FinishLoadGame(void* a_arg1) override;			// 11
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	Unk_A9(void) override;							// A9
		virtual void	Unk_AB(void) override;							// AB
		virtual void	Unk_AC(void) override;							// AC
		virtual void	Unk_B8(void) override;							// B8 - { return 0; }
		virtual void	Unk_BC(void) override;							// BC
		virtual void	Unk_BD(void) override;							// BD
		virtual void	Unk_BE(void) override;							// BE
		virtual void	Handle3DLoaded() override;						// C0

		// add
		virtual void	Unk_C2(void);									// C2 - { return 1; }


		// members
		UInt64			unk1D8;	// 1D8
		UInt64			unk1E0;	// 1E0
		UInt64			unk1E8;	// 1E8
		UInt64			unk1F0;	// 1F0
		void*			unk1F8;	// 1F8 - smart ptr
		BSTArray<void*>	unk200;	// 200
	};
	STATIC_ASSERT(sizeof(ConeProjectile) == 0x218);
}
