#pragma once

#include "RE/hkpCharacterProxy.h"


namespace RE
{
	class ahkpCharacterProxy : public hkpCharacterProxy
	{
	public:
		inline static constexpr auto RTTI = RTTI_ahkpCharacterProxy;


		virtual ~ahkpCharacterProxy();	// 00


		// members
		UInt64 unk0F0;	// 0F0
		UInt64 unk0F8;	// 0F8
	};
	STATIC_ASSERT(sizeof(ahkpCharacterProxy) == 0x100);
}
