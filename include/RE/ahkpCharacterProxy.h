#pragma once

#include "RE/hkpCharacterProxy.h"  // hkpCharacterProxy


namespace RE
{
	class ahkpCharacterProxy : public hkpCharacterProxy
	{
	public:
		virtual ~ahkpCharacterProxy();	// 00


		// members
		UInt64	unk0F0;	// 0F0
		UInt64	unk0F8;	// 0F8
	};
	STATIC_ASSERT(sizeof(ahkpCharacterProxy) == 0x100);
}
