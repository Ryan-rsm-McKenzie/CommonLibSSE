#pragma once

#include "RE/GFxEvent.h"  // GFxEvent
#include "RE/GFxKey.h"  // GFxKey
#include "RE/GFxPlayerStats.h"  // GFxStatMovieViews
#include "RE/GFxSpecialKeysState.h"  // GFxSpecialKeysState
#include "RE/GRefCountBaseNTS.h"  // GRefCountBaseNTS


namespace RE
{
	class GASStringContext;


	class GFxKeyboardState : public GRefCountBaseNTS<GFxKeyboardState, GFxStatMovieViews::kGFxStatMV_Other_Mem>
	{
	public:
		class IListener
		{
		public:
			virtual ~IListener() = default;																								// 00

			// add
			virtual void OnKeyDown(GASStringContext* a_sc, int a_code, UInt8 a_ascii, UInt32 a_charCode, UInt8 a_keyboardIndex) = 0;	// 01
			virtual void OnKeyUp(GASStringContext* a_sc, int a_code, UInt8 a_ascii, UInt32 a_charCode, UInt8 a_keyboardIndex) = 0;		// 02
			virtual void Update(int a_code, UInt8 a_ascii, UInt32 a_charCode, UInt8 a_keyboardIndex) = 0;								// 03
		};
		STATIC_ASSERT(sizeof(IListener) == 0x8);


		class KeyQueue
		{
		public:
			enum
			{
				kKeyQueueSize = 100
			};


			struct KeyRecord
			{
				UInt32				charCode;			// 00
				UInt16				code;				// 04
				UInt16				pad06;				// 06
				GFxEvent::EventType	event;				// 08
				UInt8				ascii;				// 0C
				GFxSpecialKeysState	specialKeysState;	// 0D
				UInt8				pad0E;				// 0E
				UInt8				pad0F;				// 0F
			};
			STATIC_ASSERT(sizeof(KeyRecord) == 0x10);


			// members
			KeyRecord	buffer[kKeyQueueSize];	// 000
			UInt32		putIdx;					// 640
			UInt32		getIdx;					// 644
			UInt32		count;					// 648
		};
		STATIC_ASSERT(sizeof(KeyQueue) == 0x64C);


		// members
		IListener*	listener;						// 010
		KeyQueue	keyQueue;						// 018
		UInt8		keyboardIndex;					// 664
		UInt8		keymap[GFxKey::kTotal / 8 + 1];	// 665
		bool		toggled[3];						// 682
		UInt8		pad685;							// 685
		UInt8		pad686;							// 686
		UInt8		pad687;							// 687
	};
	STATIC_ASSERT(sizeof(GFxKeyboardState) == 0x688);
}
