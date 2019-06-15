#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSSaveDataSystemUtility, RTTI_BSSaveDataSystemUtility__Entry

#include "RE/BSString.h"  // BSString
#include "RE/BSTEvent.h"  // BSTEventSource


namespace RE
{
	class BSSaveDataEvent;


	class BSSaveDataSystemUtility :
		public BSTEventSource<BSSaveDataEvent>	// 008
	{
	public:
		inline static const void* RTTI = RTTI_BSSaveDataSystemUtility;


		class Entry
		{
		public:
			inline static const void* RTTI = RTTI_BSSaveDataSystemUtility__Entry;


			virtual void Unk_00(void);	// 00


			// members
			UInt64		unk008;	// 008
			UInt64		unk010;	// 010
			UInt64		unk018;	// 018
			UInt64		unk020;	// 020
			UInt64		unk028;	// 028
			UInt64		unk030;	// 030
			UInt64		unk038;	// 038
			UInt64		unk040;	// 040
			UInt64		unk048;	// 048
			UInt64		unk050;	// 050
			UInt64		unk058;	// 058
			UInt64		unk060;	// 060
			UInt64		unk068;	// 068
			UInt64		unk070;	// 070
			UInt64		unk078;	// 078
			UInt64		unk080;	// 080
			UInt64		unk088;	// 088
			UInt64		unk090;	// 090
			UInt64		unk098;	// 098
			UInt64		unk0A0;	// 0A0
			UInt64		unk0A8;	// 0A8
			UInt64		unk0B0;	// 0B0
			UInt64		unk0B8;	// 0B8
			UInt64		unk0C0;	// 0C0
			UInt64		unk0C8;	// 0C8
			UInt64		unk0D0;	// 0D0
			UInt64		unk0D8;	// 0D8
			UInt64		unk0E0;	// 0E0
			UInt64		unk0E8;	// 0E8
			UInt64		unk0F0;	// 0F0
			UInt64		unk0F8;	// 0F8
			UInt64		unk100;	// 100
			UInt64		unk108;	// 108
			UInt64		unk110;	// 110
			UInt64		unk118;	// 118
			UInt64		unk120;	// 120
			UInt64		unk128;	// 128
			BSString	unk130;	// 130
			BSString	unk140;	// 140
			BSString	unk150;	// 150
			UInt64		unk160;	// 160
			UInt64		unk168;	// 168
			UInt64		unk170;	// 170
			UInt64		unk178;	// 178
			UInt64		unk180;	// 180
			UInt64		unk188;	// 188
			UInt64		unk190;	// 190
		};


		virtual ~BSSaveDataSystemUtility();																				// 00

		// add
		virtual bool	CreateSaveDirectory(const char* a_pathName, bool a_ignoreINI) = 0;								// 01
		virtual errno_t	PrepareFileSavePath(const char* a_fileName, char* a_dst, bool a_tmpSave, bool a_ignoreINI) = 0;	// 02 - a_dst must be 0x104 in length
		virtual void	Unk_03(void);																					// 03 - { return Unk_04(); }
		virtual void	Unk_04(void);																					// 04 - { return; }
		virtual void	Unk_05(void);																					// 05
		virtual void	Unk_06(void) = 0;																				// 06
		virtual void	Unk_07(void);																					// 07
		virtual void	Unk_08(void);																					// 08 - { return; }
		virtual void	Unk_09(void);																					// 09 - { return; }
		virtual void	Unk_0A(void);																					// 0A
		virtual void	Unk_0B(void);																					// 0B - { return; }
		virtual void	Unk_0C(void);																					// 0C
		virtual void	Unk_0D(void);																					// 0D - { return; }
		virtual void	Unk_0E(void);																					// 0E - { return 1; }
		virtual void	Unk_0F(void);																					// 0F - { return 1; }
		virtual void	Unk_10(void);																					// 10 - { return 0; }
		virtual void	Unk_11(void);																					// 11 - { return; }


		// members
		UInt32	unk060;			// 060
		UInt32	profileHash;	// 064
		UInt64	unk068;			// 068
		Entry	entry;			// 070
		UInt64	unk208;			// 208
		UInt64	unk210;			// 210
		UInt64	unk218;			// 218
		UInt64	unk220;			// 220
	};
	STATIC_ASSERT(sizeof(BSSaveDataSystemUtility) == 0x228);
}
