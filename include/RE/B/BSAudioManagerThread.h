#pragma once

#include "RE/B/BSThread.h"

namespace RE
{
	class BSAudioManagerThread : public BSThread
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSAudioManagerThread;

		virtual ~BSAudioManagerThread();  // 00

		// override (BSThread)
		virtual void Unk_01(void) override;	 // 01

		// members
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
	};
	static_assert(sizeof(BSAudioManagerThread) == 0x68);
}
