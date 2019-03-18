#pragma once


namespace RE
{
	class GFxKey
	{
	public:
		enum Code : UInt32
		{
			kVoidSymbol = 0,

			// A through Z and numbers 0 through 9.
			kA = 65,
			kB,
			kC,
			kD,
			kE,
			kF,
			kG,
			kH,
			kI,
			kJ,
			kK,
			kL,
			kM,
			kN,
			kO,
			kP,
			kQ,
			kR,
			kS,
			kT,
			kU,
			kV,
			kW,
			kX,
			kY,
			kZ,
			kNum0 = 48,
			kNum1,
			kNum2,
			kNum3,
			kNum4,
			kNum5,
			kNum6,
			kNum7,
			kNum8,
			kNum9,

			// Numeric keypad.
			kKP_0 = 96,
			kKP_1,
			kKP_2,
			kKP_3,
			kKP_4,
			kKP_5,
			kKP_6,
			kKP_7,
			kKP_8,
			kKP_9,
			kKP_Multiply,
			kKP_Add,
			kKP_Enter,
			kKP_Subtract,
			kKP_Decimal,
			kKP_Divide,

			// Function keys.
			kF1 = 112,
			kF2,
			kF3,
			kF4,
			kF5,
			kF6,
			kF7,
			kF8,
			kF9,
			kF10,
			kF11,
			kF12,
			kF13,
			kF14,
			kF15,

			// Other keys.
			kBackspace = 8,
			kTab,
			kClear = 12,
			kReturn,
			kShift = 16,
			kControl,
			kAlt,
			kPause,
			kCapsLock = 20, // Toggle
			kEscape = 27,
			kSpace = 32,
			kPageUp,
			kPageDown,
			kEnd = 35,
			kHome,
			kLeft,
			kUp,
			kRight,
			kDown,
			kInsert = 45,
			kDelete,
			kHelp,
			kNumLock = 144, // Toggle
			kScrollLock = 145, // Toggle

			kSemicolon = 186,
			kEqual = 187,
			kComma = 188, // Platform specific?
			kMinus = 189,
			kPeriod = 190, // Platform specific?
			kSlash = 191,
			kBar = 192,
			kBracketLeft = 219,
			kBackslash = 220,
			kBracketRight = 221,
			kQuote = 222,

			kOEM_AX = 0xE1,  //  'AX' key on Japanese AX kbd
			kOEM_102 = 0xE2,  //  "<>" or "\|" on RT 102-key kbd.
			kICO_HELP = 0xE3,  //  Help key on ICO
			kICO_00 = 0xE4,  //  00 key on ICO

			kTotal
		};
	};
	STATIC_ASSERT(sizeof(GFxKey) == 0x1);
}
