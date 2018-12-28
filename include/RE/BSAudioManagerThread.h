#pragma once

#include "RE/BSThread.h"  // BSThread


namespace RE
{
	class BSAudioManagerThread : public BSThread
	{
	public:
		virtual ~BSAudioManagerThread();	// 00


		// members
		UInt64	unk50;	// 50
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
	};
	STATIC_ASSERT(sizeof(BSAudioManagerThread) == 0x68);
}
