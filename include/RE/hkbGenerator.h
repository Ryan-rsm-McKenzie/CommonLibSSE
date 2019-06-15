#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkbGenerator

#include "RE/hkbNode.h"  // hkbNode


namespace RE
{
	class hkbGenerator : public hkbNode
	{
	public:
		inline static const void* RTTI = RTTI_hkbGenerator;


		virtual ~hkbGenerator();				// 00

		// override (hkbNode)
		virtual void	Unk_15(void) override;	// 15 - { return 1; }

		// add
		virtual void	Unk_17(void) = 0;		// 17
		virtual void	Unk_18(void);			// 18 - { return 0; }
		virtual void	Unk_19(void);			// 19
		virtual void	Unk_1A(void);			// 1A - { return; }
		virtual void	Unk_1B(void);			// 1B - { return; }
	};
	STATIC_ASSERT(sizeof(hkbGenerator) == 0x48);
}
