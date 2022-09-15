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

		~GrenadeProjectile() override;  // 00

		// override (Projectile)
		void           SaveGame(BGSSaveFormBuffer* a_buf) override;        // 0E
		void           LoadGame(BGSLoadFormBuffer* a_buf) override;        // 0F
		void           InitLoadGame(BGSLoadFormBuffer* a_buf) override;    // 10
		void           FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
		void           Revert(BGSLoadFormBuffer* a_buf) override;          // 12
		BGSDecalGroup* GetDecalGroup() const override;                     // 9F - { return decalGroup; }
		void           Unk_A3(void) override;                              // A3 - { return 1; }
		void           Unk_A8(void) override;                              // A8
		void           Unk_A9(void) override;                              // A9
		void           UpdateImpl(float a_delta) override;                 // AB
		void           Unk_AE(void) override;                              // AE
		void           Unk_B2(void) override;                              // B2
		void           Unk_B3(void) override;                              // B3
		bool           IsNotGeneratedForm() const override;                // B4
		void           Unk_BA(void) override;                              // BA - { return 1; }
		void           Unk_BB(void) override;                              // BB
		void           Unk_BD(void) override;                              // BD
		void           Unk_BF(void) override;                              // BF - { flags |= 1 << 30; }
		void           Handle3DLoaded() override;                          // C0

		// members
		BGSDecalGroup* decalGroup;           // 1D8
		bool           collisionGroupReset;  // 1E0
		std::uint8_t   pad1E1;               // 1E1
		std::uint16_t  pad1E2;               // 1E2
		std::uint32_t  pad1E4;               // 1E4
	};
	static_assert(sizeof(GrenadeProjectile) == 0x1F0);
}
