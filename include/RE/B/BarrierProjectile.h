#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class BarrierProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_BarrierProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileBarrier;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		struct CollisionData
		{
			ObjectRefHandle ref;    // 0
			std::uint32_t   count;  // 4
		};
		static_assert(sizeof(CollisionData) == 0x8);

		~BarrierProjectile() override;  // 00

		// override (Projectile)
		void        SaveGame(BGSSaveFormBuffer* a_buf) override;        // 0E
		void        LoadGame(BGSLoadFormBuffer* a_buf) override;        // 0F
		void        InitLoadGame(BGSLoadFormBuffer* a_buf) override;    // 10
		void        FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
		void        Revert(BGSLoadFormBuffer* a_buf) override;          // 12
		void        InitHavok() override;                               // 66
		NiAVObject* Load3D(bool a_backgroundLoading) override;          // 6A
		void        Unk_A7(void) override;                              // A7 - { return 1; }
		void        UpdateImpl(float a_delta) override;                 // AB
		void        Unk_AC(void) override;                              // AC
		void        Unk_B8(void) override;                              // B8 - { return 0; }

		// members
		float                   width;          // 1D8
		std::uint32_t           pad1DC;         // 1DC
		BSTArray<CollisionData> collisionData;  // 1E0
	};
	static_assert(sizeof(BarrierProjectile) == 0x200);
}
