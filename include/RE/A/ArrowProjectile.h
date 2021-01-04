#pragma once

#include "RE/F/FormTypes.h"
#include "RE/M/MissileProjectile.h"

namespace RE
{
	class AlchemyItem;

	class ArrowProjectile : public MissileProjectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_ArrowProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileArrow;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		virtual ~ArrowProjectile();	 // 00

		// override (MissileProjectile)
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Unk_AA(void) override;						   // AA
		virtual void UpdateImpl(float a_delta) override;		   // AB
		virtual void Unk_AC(void) override;						   // AC
		virtual void Unk_AD(void) override;						   // AD
		virtual void Unk_AF(void) override;						   // AF
		virtual void Unk_B0(void) override;						   // B0
		virtual void Unk_B1(void) override;						   // B1 - { return 1; }
		virtual void Unk_B5(void) override;						   // B5
		virtual void Unk_B9(void) override;						   // B9 - { return (unk1CC >> 22) & 1; }
		virtual void Unk_BD(void) override;						   // BD
		virtual void Handle3DLoaded() override;					   // C0
		virtual void Unk_C2(void) override;						   // C2 - { return 1; }
		virtual void Unk_C3(void) override;						   // C3 - { return 1; }

		// members
		std::uint64_t unk1E0;  // 1E0
		AlchemyItem*  poison;  // 1E8
	};
	static_assert(sizeof(ArrowProjectile) == 0x1F0);
}
