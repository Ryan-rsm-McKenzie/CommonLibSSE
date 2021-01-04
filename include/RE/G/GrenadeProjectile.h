#pragma once

#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	struct BGSDecalGroup;

	class GrenadeProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_GrenadeProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileGrenade;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		virtual ~GrenadeProjectile();  // 00

		// override (Projectile)
		virtual void		   SaveGame(BGSSaveFormBuffer* a_buf) override;		   // 0E
		virtual void		   LoadGame(BGSLoadFormBuffer* a_buf) override;		   // 0F
		virtual void		   InitLoadGame(BGSLoadFormBuffer* a_buf) override;	   // 10
		virtual void		   FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
		virtual void		   Revert(BGSLoadFormBuffer* a_buf) override;		   // 12
		virtual BGSDecalGroup* GetDecalGroup() const override;					   // 9F - { return decalGroup; }
		virtual void		   Unk_A3(void) override;							   // A3 - { return 1; }
		virtual void		   Unk_A8(void) override;							   // A8
		virtual void		   Unk_A9(void) override;							   // A9
		virtual void		   UpdateImpl(float a_delta) override;				   // AB
		virtual void		   Unk_AE(void) override;							   // AE
		virtual void		   Unk_B2(void) override;							   // B2
		virtual void		   Unk_B3(void) override;							   // B3
		virtual bool		   IsNotGeneratedForm() const override;				   // B4
		virtual void		   Unk_BA(void) override;							   // BA - { return 1; }
		virtual void		   Unk_BB(void) override;							   // BB
		virtual void		   Unk_BD(void) override;							   // BD
		virtual void		   Unk_BF(void) override;							   // BF - { flags |= 1 << 30; }
		virtual void		   Handle3DLoaded() override;						   // C0

		// members
		BGSDecalGroup* decalGroup;			 // 1D8
		bool		   collisionGroupReset;	 // 1E0
		std::uint8_t   pad1E1;				 // 1E1
		std::uint16_t  pad1E2;				 // 1E2
		std::uint32_t  pad1E4;				 // 1E4
	};
	static_assert(sizeof(GrenadeProjectile) == 0x1E8);
}
