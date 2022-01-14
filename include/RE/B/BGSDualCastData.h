#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	struct BGSDualCastDataDEF  // DATA
	{
	public:
		enum class Flags
		{
			kNone = 0,
			kHitEffectInheritScale = 1 << 0,
			kProjectileInheritScale = 1 << 1,
			kExplosionInheritScale = 1 << 2
		};

		// members
		BGSProjectile*                         pProjectile;     // 00
		BGSExplosion*                          pExplosion;      // 08
		TESEffectShader*                       pEffectShader;   // 10
		BGSArtObject*                          pHitEffectArt;   // 18
		BGSImpactDataSet*                      pImpactDataSet;  // 20
		stl::enumeration<Flags, std::uint32_t> flags;           // 28
		std::uint32_t                          pad30;           // 30
	};
	static_assert(sizeof(BGSDualCastDataDEF) == 0x30);

	class BGSDualCastData : public TESBoundObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDualCastData;
		inline static constexpr auto VTABLE = VTABLE_BGSDualCastData;
		inline static constexpr auto FORMTYPE = FormType::DualCastData;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSDualCastData() override;  // 00

		// override (TESBoundObject)
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BGSDualCastDataDEF data;  // 30 - DATA
	};
	static_assert(sizeof(BGSDualCastData) == 0x60);
}
