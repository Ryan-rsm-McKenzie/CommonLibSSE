#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/E/ExtraMagicCaster.h"

namespace RE
{
	class TESObjectREFR;

	class NonActorMagicCaster : public ExtraMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_NonActorMagicCaster;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMagicCaster;

		~NonActorMagicCaster() override;  // 00

		// override (MagicCaster)
		void           Unk_01(void) override;                        // 01
		void           Unk_07(void) override;                        // 07 - { return; }
		TESObjectREFR* GetTarget() override;                         // 0B - { return 0; }
		Actor*         GetCaster() override;                         // 0C - { return 0; }
		void           Unk_0D(void) override;                        // 0D
		NiNode*        GetMagicNode() override;                      // 0E - { return 0; }
		void           SaveGame(BGSSaveGameBuffer* a_buf) override;  // 18
		void           LoadGame(BGSLoadGameBuffer* a_buf) override;  // 19

		// members
		TESObjectREFR* unk58;       // 58
		ActorHandle    blameActor;  // 60
		std::uint32_t  unk64;       // 64
	};
	static_assert(sizeof(NonActorMagicCaster) == 0x68);
}
