#pragma once

#include "RE/G/GFxEvent.h"
#include "RE/G/GFxKey.h"
#include "RE/G/GFxPlayerStats.h"
#include "RE/G/GFxSpecialKeysState.h"
#include "RE/G/GRefCountBaseNTS.h"

namespace RE
{
	class GASStringContext;

	class GFxKeyboardState : public GRefCountBaseNTS<GFxKeyboardState, GFxStatMovieViews::kGFxStatMV_Other_Mem>
	{
	public:
		class IListener
		{
		public:
			virtual ~IListener() = default;  // 00

			// add
			virtual void OnKeyDown(GASStringContext* a_sc, int a_code, std::uint8_t a_ascii, std::uint32_t a_charCode, std::uint8_t a_keyboardIndex) = 0;  // 01
			virtual void OnKeyUp(GASStringContext* a_sc, int a_code, std::uint8_t a_ascii, std::uint32_t a_charCode, std::uint8_t a_keyboardIndex) = 0;    // 02
			virtual void Update(int a_code, std::uint8_t a_ascii, std::uint32_t a_charCode, std::uint8_t a_keyboardIndex) = 0;                             // 03
		};
		static_assert(sizeof(IListener) == 0x8);

		class KeyQueue
		{
		public:
			enum
			{
				kKeyQueueSize = 100
			};

			struct KeyRecord
			{
				std::uint32_t       charCode;          // 00
				std::uint16_t       code;              // 04
				std::uint16_t       pad06;             // 06
				GFxEvent::EventType event;             // 08
				std::uint8_t        ascii;             // 0C
				GFxSpecialKeysState specialKeysState;  // 0D
				std::uint8_t        pad0E;             // 0E
				std::uint8_t        pad0F;             // 0F
			};
			static_assert(sizeof(KeyRecord) == 0x10);

			// members
			KeyRecord     buffer[kKeyQueueSize];  // 000
			std::uint32_t putIdx;                 // 640
			std::uint32_t getIdx;                 // 644
			std::uint32_t count;                  // 648
		};
		static_assert(sizeof(KeyQueue) == 0x64C);

		// members
		IListener*   listener;                        // 010
		KeyQueue     keyQueue;                        // 018
		std::uint8_t keyboardIndex;                   // 664
		std::uint8_t keymap[GFxKey::kTotal / 8 + 1];  // 665
		bool         toggled[3];                      // 682
		std::uint8_t pad685;                          // 685
		std::uint8_t pad686;                          // 686
		std::uint8_t pad687;                          // 687
	};
	static_assert(sizeof(GFxKeyboardState) == 0x688);
}
