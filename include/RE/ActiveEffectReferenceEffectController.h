#pragma once

#include "RE/ReferenceEffectController.h"  // ReferenceEffectController


namespace RE
{
	class ActiveEffect;


	class ActiveEffectReferenceEffectController : public ReferenceEffectController
	{
	public:
		virtual ~ActiveEffectReferenceEffectController();	// 00


		// members
		ActiveEffect*	effect;	// 08
		UInt64			unk10;	// 10
		UInt64			unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ActiveEffectReferenceEffectController) == 0x20);
}
