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

		~ArrowProjectile() override;  // 00

		// override (MissileProjectile)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		void Unk_AA(void) override;                        // AA
		void UpdateImpl(float a_delta) override;           // AB
		void Unk_AC(void) override;                        // AC
		void Unk_AD(void) override;                        // AD
		void Unk_AF(void) override;                        // AF
		void Unk_B0(void) override;                        // B0
		void Unk_B1(void) override;                        // B1 - { return 1; }
		void Unk_B5(void) override;                        // B5
		void Unk_B9(void) override;                        // B9 - { return (unk1CC >> 22) & 1; }
		void Unk_BD(void) override;                        // BD
		void Handle3DLoaded() override;                    // C0
		void Unk_C2(void) override;                        // C2 - { return 1; }
		void Unk_C3(void) override;                        // C3 - { return 1; }

		// members
		std::uint64_t unk1E0;  // 1E0
		AlchemyItem*  poison;  // 1E8
	};
	static_assert(sizeof(ArrowProjectile) == 0x1F8);
}
