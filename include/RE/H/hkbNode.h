#pragma once

#include "RE/H/hkStringPtr.h"
#include "RE/H/hkbBindable.h"

namespace RE
{
	class hkbNode : public hkbBindable
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbNode;

		~hkbNode() override;  // 00

		// add
		virtual void Unk_04();  // 04 - { return; }
		virtual void Unk_05();  // 05 - { userData |= 1; }
		virtual void Unk_06();  // 06 - { return; }
		virtual void Unk_07();  // 07 - { return; }
		virtual void Unk_08();  // 08 - { return 2; }
		virtual void Unk_09();  // 09 - { return; }
		virtual void Unk_0A();  // 0A - { return 1; }
		virtual void Unk_0B();  // 0B - { return; }
		virtual void Unk_0C();  // 0C
		virtual void Unk_0D();  // 0D - { return 0; }
		virtual void Unk_0E();  // 0E - { return; }
		virtual void Unk_0F();  // 0F - { return; }
		virtual void Unk_10();  // 10 - { return; }
		virtual void Unk_11();  // 11 - { return; }
		virtual void Unk_12();  // 12 - { return; }
		virtual void Unk_13();  // 13 - { return 0; }
		virtual void Unk_14();  // 14 - { return; }
		virtual void Unk_15();  // 15 - { return 0; }
		virtual void Unk_16();  // 16 - { return 0; }

		enum class GetChildrenFlagBits
		{
			kActiveOnly = 1 << 0,
			kGeneratorsOnly = 1 << 1,
			kIgnoreReferencedBehaviour = 1 << 2
		};

		enum class CloneState
		{
			kDefault = 0,
			kTemplate = 1,
			kClone = 2,
			kShareable = 3
		};

		// members
		std::uint32_t                              userData;    // 30
		std::uint32_t                              pad34;       // 34
		hkStringPtr                                name;        // 38
		std::uint16_t                              id;          // 40
		stl::enumeration<CloneState, std::uint8_t> cloneState;  // 42
		std::uint8_t                               pad43;       // 43
		std::uint32_t                              pad44;       // 44
	};
	static_assert(sizeof(hkbNode) == 0x48);
}
