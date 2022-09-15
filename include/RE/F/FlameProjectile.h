#pragma once

#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class FlameProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_FlameProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileFlame;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~FlameProjectile() override;  // 00

		// override (Projectile)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;        // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;        // 0F
		void InitLoadGame(BGSLoadFormBuffer* a_buf) override;    // 10
		void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
		void Revert(BGSLoadFormBuffer* a_buf) override;          // 12
		void Unk_A4(void) override;                              // A4 - { return 1; }
		void Unk_A9(void) override;                              // A9
		void UpdateImpl(float a_delta) override;                 // AB
		void Unk_B7(void) override;                              // B7
		void Unk_BD(void) override;                              // BD
		void Handle3DLoaded() override;                          // C0 - { flags = flags & 0xFFFFFFCC | 8; }
		void Unk_C1(void) override;                              // C1

		// members
		float expirationTimer;  // 1D8
		float coneAngle;        // 1DC
	};
	static_assert(sizeof(FlameProjectile) == 0x1E8);
}
