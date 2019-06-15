#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Stars

#include "RE/SkyObject.h"  // SkyObject


namespace RE
{
	class NiNode;


	class Stars : public SkyObject
	{
	public:
		inline static const void* RTTI = RTTI_Stars;


		virtual ~Stars();					// 00

		// override (SkyObject)
		virtual void Unk_03(void) override;	// 03


		// members
		NiNode*	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(Stars) == 0x20);
}
