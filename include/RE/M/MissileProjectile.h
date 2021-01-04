#pragma once

#include "RE/F/FormTypes.h"
#include "RE/I/ImpactResults.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class MissileProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_MissileProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileMissile;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		virtual ~MissileProjectile();  // 00

		// override (Projectile)
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;		 // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;		 // 0F
		virtual void InitLoadGame(BGSLoadFormBuffer* a_buf) override;	 // 10
		virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;	 // 11
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;			 // 12
		virtual void Unk_A2(void) override;								 // A2 - { return 1; }
		virtual void Unk_A9(void) override;								 // A9
		virtual void UpdateImpl(float a_delta) override;				 // AB
		virtual void Unk_AC(void) override;								 // AC
		virtual void Unk_B8(void) override;								 // B8 - { return unk1D8 == 1; }
		virtual void Unk_BD(void) override;								 // BD
		virtual void Handle3DLoaded() override;							 // C0

		// add
		virtual void Unk_C2(void);	// C2 - { return 0; }
		virtual void Unk_C3(void);	// C3 - { return 0; }

		// members
		ImpactResult  impactResult;			  // 1D8
		bool		  waitingToInitialize3D;  // 1DC
		std::uint8_t  unk1DD;				  // 1DD
		std::uint16_t unk1DE;				  // 1DE
	};
	static_assert(sizeof(MissileProjectile) == 0x1E0);
}
