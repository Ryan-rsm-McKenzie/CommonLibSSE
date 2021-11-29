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
		void Unk_01(void) override;  // 01
		void Unk_02(void) override;  // 02
		void Unk_03(void) override;  // 03
		void Unk_04(void) override;  // 04
		void Unk_05(void) override;  // 05 - { return; }
		void Unk_06(void) override;  // 06 - { return; }
		void Unk_07(void) override;  // 07
		void Unk_08(void) override;  // 08
		void Unk_09(void) override;  // 09
		void Unk_0A(void) override;  // 0A
		void Unk_0B(void) override;  // 0B
		void Unk_0C(void) override;  // 0C
		void Unk_0D(void) override;  // 0D

		// members
		std::uint64_t unkB8;  // B8
	};
	static_assert(sizeof(BGSMoviePlayer) == 0xC0);
}
