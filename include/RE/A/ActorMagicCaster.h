#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/M/MagicCaster.h"
#include "RE/R/RefAttachTechniqueInput.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	struct BSAnimationGraphEvent;
	class BGSArtObject;
	class ReferenceEffectController;
	class BSLight;

	class ActorMagicCaster :
		public MagicCaster,                         // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorMagicCaster;

		enum class Flags
		{
			kNone = 0,
			kDualCasting = 1 << 0,
			kUsesHands = 1 << 4
		};

		~ActorMagicCaster() override;  // 00

		// override (MagicCaster)
		void                       Unk_03(void) override;                        // 03
		void                       Unk_04(void) override;                        // 04
		void                       Unk_05(void) override;                        // 05
		void                       Unk_06(void) override;                        // 06
		void                       Unk_07(void) override;                        // 07 - { return; }
		void                       Unk_08(void) override;                        // 08 - { return; }
		void                       Unk_09(void) override;                        // 09 - { return; }
		void                       Unk_0A(void) override;                        // 0A
		TESObjectREFR*             GetTarget() override;                         // 0B - { return actor; }
		Actor*                     GetCaster() override;                         // 0C - { return actor; }
		NiNode*                    GetMagicNode() override;                      // 0E - { return magicNode; }
		void                       ClearMagicNode() override;                    // 0F - { magicNode = 0; }
		void                       Unk_10(void) override;                        // 10 - { return; }
		void                       AttachCastingArt() override;                  // 11 - { return; }
		void                       DetachCastingArt() override;                  // 12 - { return; }
		void                       Unk_13(void) override;                        // 13 - { return; }
		void                       CalculateMagickaCost() override;              // 14
		MagicSystem::CastingSource GetCastingSource() override;                  // 15 - { return castingSource; }
		bool                       IsDualCasting() override;                     // 16 - { return flags & 1; }
		void                       SetDualCasting(bool a_set) override;          // 17
		void                       SaveGame(BGSSaveGameBuffer* a_buf) override;  // 18
		void                       LoadGame(BGSLoadGameBuffer* a_buf) override;  // 19
		void                       Unk_1A(void) override;                        // 1A
		void                       Unk_1B(void) override;                        // 1B
		void                       Unk_1C(void) override;                        // 1C

		// add
		virtual void Unk_1D(void);  // 1D

		// members
		RefAttachTechniqueInput                unk64;                        // 64
		std::uint64_t                          unkB0;                        // B0
		Actor*                                 actor;                        // B8
		NiNode*                                magicNode;                    // C0
		NiPointer<BSLight>                     light;                        // C8
		std::uint64_t                          unkD0;                        // D0
		std::uint64_t                          unkD8;                        // D8
		BGSArtObject*                          castingArt;                   // E0
		ReferenceEffectController*             weaponEnchantmentController;  // E8
		std::uint32_t                          unkF0;                        // F0
		MagicSystem::CastingSource             castingSource;                // F4
		stl::enumeration<Flags, std::uint32_t> flags;                        // F8
	};
	static_assert(sizeof(ActorMagicCaster) == 0x100);
}
