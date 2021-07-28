#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/M/MoviePlayer.h"

namespace RE
{
	class InputEvent;
	struct BSMusicEvent;

	class BGSMoviePlayer :
		public MoviePlayer,                  // 00
		public BSTEventSink<InputEvent*>,    // 58
		public BSTEventSource<BSMusicEvent>  // 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMoviePlayer;

		~BGSMoviePlayer() override;  // 00

		// override (MoviePlayer)
		void Unk_01() override;  // 01
		void Unk_02() override;  // 02
		void Unk_03() override;  // 03
		void Unk_04() override;  // 04
		void Unk_05() override;  // 05 - { return; }
		void Unk_06() override;  // 06 - { return; }
		void Unk_07() override;  // 07
		void Unk_08() override;  // 08
		void Unk_09() override;  // 09
		void Unk_0A() override;  // 0A
		void Unk_0B() override;  // 0B
		void Unk_0C() override;  // 0C
		void Unk_0D() override;  // 0D

		// members
		std::uint64_t unkB8;  // B8
	};
	static_assert(sizeof(BGSMoviePlayer) == 0xC0);
}
