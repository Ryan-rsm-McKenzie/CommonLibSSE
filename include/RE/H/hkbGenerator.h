#pragma once

#include "RE/H/hkbNode.h"

namespace RE
{
	class hkbGenerator : public hkbNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbGenerator;

		~hkbGenerator() override;  // 00

		// override (hkbNode)
		void Unk_15() override;  // 15 - { return 1; }

		// add
		virtual void Unk_17() = 0;  // 17
		virtual void Unk_18();      // 18 - { return 0; }
		virtual void Unk_19();      // 19
		virtual void Unk_1A();      // 1A - { return; }
		virtual void Unk_1B();      // 1B - { return; }
	};
	static_assert(sizeof(hkbGenerator) == 0x48);
}
