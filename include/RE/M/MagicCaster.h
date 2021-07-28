#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"

namespace RE
{
	class MagicItem;

	class MagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicCaster;

		enum class State
		{
		};

		virtual ~MagicCaster();  // 00

		// add
		virtual void Unk_01();  // 01
		virtual void Unk_02();  // 02
		virtual void Unk_03();  // 03
		virtual void Unk_04();  // 04
		virtual void Unk_05();  // 05
		virtual void Unk_06();  // 06
		virtual void Unk_07();  // 07 - { return; }
		virtual void Unk_08();  // 08 - { return; }
		virtual void Unk_09();  // 09 - { return; }
		virtual void Unk_0A();  // 0A
		virtual void Unk_0B();  // 0B - { return 0; }
		virtual void Unk_0C();  // 0C - { return 0; }
		virtual void Unk_0D();  // 0D
		virtual void Unk_0E();  // 0E - { return 0; }
		virtual void Unk_0F();  // 0F - { return; }
		virtual void Unk_10();  // 10 - { return; }
		virtual void Unk_11();  // 11 - { return; }
		virtual void Unk_12();  // 12 - { return; }
		virtual void Unk_13();  // 13 - { return; }
		virtual void Unk_14();  // 14
		virtual void Unk_15();  // 15 - { return 0; }
		virtual void Unk_16();  // 16 - { return 0; }
		virtual void Unk_17();  // 17 - { return; }
		virtual void Unk_18();  // 18
		virtual void Unk_19();  // 19
		virtual void Unk_1A();  // 1A
		virtual void Unk_1B();  // 1B
		virtual void Unk_1C();  // 1C

		// members
		BSTArray<BSSoundHandle>                sounds;             // 08
		ObjectRefHandle                        desiredTarget;      // 20
		std::uint32_t                          pad24;              // 24
		MagicItem*                             currentSpell;       // 28
		stl::enumeration<State, std::uint32_t> state;              // 30
		float                                  castingTimer;       // 34
		float                                  currentSpellCost;   // 38
		float                                  magnitudeOverride;  // 3C
		float                                  nextTargetUpdate;   // 40
		float                                  projectileTimer;    // 44
	};
	static_assert(sizeof(MagicCaster) == 0x48);
}
