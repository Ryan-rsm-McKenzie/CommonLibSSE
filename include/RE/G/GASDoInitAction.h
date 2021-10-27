#pragma once

#include "RE/G/GASDoAction.h"

namespace RE
{
	class GASDoInitAction : public GASDoAction
	{
	public:
		virtual ~GASDoInitAction();  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		bool Unk_04() override;                       // 04 - { return 0; }
	};
	static_assert(sizeof(GASDoInitAction) == 0x10);
}
