#pragma once

#include "RE/H/hkbNode.h"

namespace RE
{
	class hkbGenerator : public hkbNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbGenerator;

		virtual ~hkbGenerator();  // 00

		// override (hkbNode)
		virtual void Unk_15(void) override;	 // 15 - { return 1; }

		// add
		virtual void Unk_17(void) = 0;	// 17
		virtual void Unk_18(void);		// 18 - { return 0; }
		virtual void Unk_19(void);		// 19
		virtual void Unk_1A(void);		// 1A - { return; }
		virtual void Unk_1B(void);		// 1B - { return; }
	};
	static_assert(sizeof(hkbGenerator) == 0x48);
}
