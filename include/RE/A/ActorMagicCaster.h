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

		virtual ~ActorMagicCaster();  // 00

		// override
		virtual void                       Unk_03(void) override;                        // 03
		virtual void                       Unk_04(void) override;                        // 04
		virtual void                       Unk_05(void) override;                        // 05
		virtual void                       Unk_06(void) override;                        // 06
		virtual void                       Unk_07(void) override;                        // 07 - { return; }
		virtual void                       Unk_08(void) override;                        // 08 - { return; }
		virtual void                       Unk_09(void) override;                        // 09 - { return; }
		virtual void                       Unk_0A(void) override;                        // 0A
		virtual TESObjectREFR*             GetTarget() override;                         // 0B - { return actor; }
		virtual Actor*                     GetCaster() override;                         // 0C - { return actor; }
		virtual NiNode*                    GetMagicNode() override;                      // 0E - { return magicNode; }
		virtual void                       ClearMagicNode() override;                    // 0F - { magicNode = 0; }
		virtual void                       Unk_10(void) override;                        // 10 - { return; }
		virtual void                       AttachCastingArt() override;                  // 11 - { return; }
		virtual void                       DetachCastingArt() override;                  // 12 - { return; }
		virtual void                       Unk_13(void) override;                        // 13 - { return; }
		virtual void                       CalculateMagickaCost() override;              // 14
		virtual MagicSystem::CastingSource GetCastingSource() override;                  // 15 - { return castingSource; }
		virtual bool                       IsDualCasting() override;                     // 16 - { return flags & 1; }
		virtual void                       SetDualCasting(bool a_set) override;          // 17
		virtual void                       SaveGame(BGSSaveGameBuffer* a_buf) override;  // 18
		virtual void                       LoadGame(BGSLoadGameBuffer* a_buf) override;  // 19
		virtual void                       Unk_1A(void) override;                        // 1A
		virtual void                       Unk_1B(void) override;                        // 1B
		virtual void                       Unk_1C(void) override;                        // 1C

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
