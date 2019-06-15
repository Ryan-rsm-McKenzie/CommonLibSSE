#pragma once


#include "skse64/GameRTTI.h"  // RTTI_SkyObject

namespace RE
{
	class NiNode;


	class SkyObject
	{
	public:
		inline static const void* RTTI = RTTI_SkyObject;


		virtual ~SkyObject();			// 00

		// add
		virtual void	Unk_01(void);	// 01 - { return unk08; }
		virtual void	Unk_02(void);	// 02
		virtual void	Unk_03(void);	// 03 - { return; }


		// members
		NiNode* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(SkyObject) == 0x10);
}
