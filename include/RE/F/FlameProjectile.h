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

		virtual ~FlameProjectile();	 // 00

		// override (Projectile)
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;		 // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;		 // 0F
		virtual void InitLoadGame(BGSLoadFormBuffer* a_buf) override;	 // 10
		virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;	 // 11
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;			 // 12
		virtual void Unk_A4(void) override;								 // A4 - { return 1; }
		virtual void Unk_A9(void) override;								 // A9
		virtual void UpdateImpl(float a_delta) override;				 // AB
		virtual void Unk_B7(void) override;								 // B7
		virtual void Unk_BD(void) override;								 // BD
		virtual void Handle3DLoaded() override;							 // C0 - { flags = flags & 0xFFFFFFCC | 8; }
		virtual void Unk_C1(void) override;								 // C1

		// members
		float expirationTimer;	// 1D8
		float coneAngle;		// 1DC
	};
	static_assert(sizeof(FlameProjectile) == 0x1E0);
}
