#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class BSSaveDataEvent;

	class BSSaveDataSystemUtility :
		public BSTEventSource<BSSaveDataEvent>  // 008
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSaveDataSystemUtility;

		class Entry
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSSaveDataSystemUtility__Entry;

			virtual void Unk_00(void);  // 00

			// members
			std::uint64_t unk008;  // 008
			std::uint64_t unk010;  // 010
			std::uint64_t unk018;  // 018
			std::uint64_t unk020;  // 020
			std::uint64_t unk028;  // 028
			std::uint64_t unk030;  // 030
			std::uint64_t unk038;  // 038
			std::uint64_t unk040;  // 040
			std::uint64_t unk048;  // 048
			std::uint64_t unk050;  // 050
			std::uint64_t unk058;  // 058
			std::uint64_t unk060;  // 060
			std::uint64_t unk068;  // 068
			std::uint64_t unk070;  // 070
			std::uint64_t unk078;  // 078
			std::uint64_t unk080;  // 080
			std::uint64_t unk088;  // 088
			std::uint64_t unk090;  // 090
			std::uint64_t unk098;  // 098
			std::uint64_t unk0A0;  // 0A0
			std::uint64_t unk0A8;  // 0A8
			std::uint64_t unk0B0;  // 0B0
			std::uint64_t unk0B8;  // 0B8
			std::uint64_t unk0C0;  // 0C0
			std::uint64_t unk0C8;  // 0C8
			std::uint64_t unk0D0;  // 0D0
			std::uint64_t unk0D8;  // 0D8
			std::uint64_t unk0E0;  // 0E0
			std::uint64_t unk0E8;  // 0E8
			std::uint64_t unk0F0;  // 0F0
			std::uint64_t unk0F8;  // 0F8
			std::uint64_t unk100;  // 100
			std::uint64_t unk108;  // 108
			std::uint64_t unk110;  // 110
			std::uint64_t unk118;  // 118
			std::uint64_t unk120;  // 120
			std::uint64_t unk128;  // 128
			BSString      unk130;  // 130
			BSString      unk140;  // 140
			BSString      unk150;  // 150
			std::uint64_t unk160;  // 160
			std::uint64_t unk168;  // 168
			std::uint64_t unk170;  // 170
			std::uint64_t unk178;  // 178
			std::uint64_t unk180;  // 180
			std::uint64_t unk188;  // 188
			std::uint64_t unk190;  // 190
		};

		virtual ~BSSaveDataSystemUtility();  // 00

		// add
		virtual bool    CreateSaveDirectory(const char* a_pathName, bool a_ignoreINI) = 0;                               // 01
		virtual errno_t PrepareFileSavePath(const char* a_fileName, char* a_dst, bool a_tmpSave, bool a_ignoreINI) = 0;  // 02 - a_dst must be 0x104 in length
		virtual void    Unk_03(void);                                                                                    // 03 - { return Unk_04(); }
		virtual void    Unk_04(void);                                                                                    // 04 - { return; }
		virtual void    Unk_05(void);                                                                                    // 05
		virtual void    Unk_06(void) = 0;                                                                                // 06
		virtual void    Unk_07(void);                                                                                    // 07
		virtual void    Unk_08(void);                                                                                    // 08 - { return; }
		virtual void    Unk_09(void);                                                                                    // 09 - { return; }
		virtual void    Unk_0A(void);                                                                                    // 0A
		virtual void    Unk_0B(void);                                                                                    // 0B - { return; }
		virtual void    Unk_0C(void);                                                                                    // 0C
		virtual void    Unk_0D(void);                                                                                    // 0D - { return; }
		virtual void    Unk_0E(void);                                                                                    // 0E - { return 1; }
		virtual void    Unk_0F(void);                                                                                    // 0F - { return 1; }
		virtual void    Unk_10(void);                                                                                    // 10 - { return 0; }
		virtual void    Unk_11(void);                                                                                    // 11 - { return; }

		// members
		std::uint32_t unk060;       // 060
		std::uint32_t profileHash;  // 064
		std::uint64_t unk068;       // 068
		Entry         entry;        // 070
		std::uint64_t unk208;       // 208
		std::uint64_t unk210;       // 210
		std::uint64_t unk218;       // 218
		std::uint64_t unk220;       // 220
	};
	static_assert(sizeof(BSSaveDataSystemUtility) == 0x228);
}
