#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/H/hkRefPtr.h"
#include "RE/I/ImpactResults.h"
#include "RE/N/NiPoint3.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class hkpSphereShape;

	class ConeProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_ConeProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileCone;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		virtual ~ConeProjectile();	// 00

		// override (Projectile)
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;		 // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;		 // 0F
		virtual void InitLoadGame(BGSLoadFormBuffer* a_buf) override;	 // 10
		virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;	 // 11
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;			 // 12
		virtual void Unk_A9(void) override;								 // A9
		virtual void UpdateImpl(float a_delta) override;				 // AB
		virtual void Unk_AC(void) override;								 // AC
		virtual void Unk_B8(void) override;								 // B8 - { return 0; }
		virtual void Unk_BC(void) override;								 // BC
		virtual void Unk_BD(void) override;								 // BD
		virtual void Unk_BE(void) override;								 // BE
		virtual void Handle3DLoaded() override;							 // C0

		// add
		virtual void Unk_C2(void);	// C2 - { return 1; }

		// members
		ImpactResult			 impactResult;					// 1D8
		float					 environmentTimer;				// 1DC
		float					 coneAngleTangent;				// 1E0
		float					 initialCollisionSphereRadius;	// 1E4
		NiPoint3				 origin;						// 1E8
		std::uint32_t			 pad1F4;						// 1F4
		hkRefPtr<hkpSphereShape> collisionShape;				// 1F8
		BSTArray<void*>			 collisions;					// 200
	};
	static_assert(sizeof(ConeProjectile) == 0x218);
}
