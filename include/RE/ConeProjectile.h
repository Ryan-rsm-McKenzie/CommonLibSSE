#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/hkRefPtr.h"
#include "RE/NiPoint3.h"
#include "RE/Projectile.h"


namespace RE
{
	class hkpSphereShape;


	enum class ImpactResult : UInt32
	{
		kNone = 0,
		kDestroy = 1,
		kBounce = 2,
		kImpale = 3,
		kStick = 4
	};


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
		ImpactResult				impactResult;					// 1D8
		float						environmentTimer;				// 1DC
		float						coneAngleTangent;				// 1E0
		float						initialCollisionSphereRadius;	// 1E4
		NiPoint3					origin;							// 1E8
		UInt32						pad1F4;							// 1F4
		hkRefPtr<hkpSphereShape>	collisionShape;					// 1F8
		BSTArray<void*>				collisions;						// 200
	};
	STATIC_ASSERT(sizeof(ConeProjectile) == 0x218);
}
