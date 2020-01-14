#pragma once

#include "RE/BSPointerHandle.h"
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


		struct CollisionData
		{
			ObjectRefHandle	ref;	// 0
			UInt32			count;	// 4
		};
		STATIC_ASSERT(sizeof(CollisionData) == 0x8);


		virtual ~BarrierProjectile();											// 00

		// override (Projectile)
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;		// 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;		// 0F
		virtual void		InitLoadGame(BGSLoadFormBuffer* a_arg1) override;	// 10
		virtual void		FinishLoadGame(BGSLoadFormBuffer* a_arg1) override;	// 11
		virtual void		Revert(BGSLoadFormBuffer* a_arg1) override;			// 12
		virtual void		InitHavok() override;								// 66
		virtual NiAVObject*	Load3D(bool a_arg1) override;						// 6A
		virtual void		Unk_A7(void) override;								// A7 - { return 1; }
		virtual void		Unk_AB(void) override;								// AB
		virtual void		Unk_AC(void) override;								// AC
		virtual void		Unk_B8(void) override;								// B8 - { return 0; }


		// members
		float					width;			// 1D8
		UInt32					pad1DC;			// 1DC
		BSTArray<CollisionData>	collisionData;	// 1E0
	};
	STATIC_ASSERT(sizeof(BarrierProjectile) == 0x1F8);
}
