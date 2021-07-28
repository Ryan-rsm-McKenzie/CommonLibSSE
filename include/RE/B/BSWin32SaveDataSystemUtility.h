#pragma once

#include "RE/B/BSSaveDataSystemUtility.h"

namespace RE
{
	class BSWin32SaveDataSystemUtility : public BSSaveDataSystemUtility
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32SaveDataSystemUtility;

		~BSWin32SaveDataSystemUtility() override;

		// override (BSSaveDataSystemUtility)
		bool    CreateSaveDirectory(const char* a_pathName, bool a_ignoreINI) override;                               // 01
		errno_t PrepareFileSavePath(const char* a_fileName, char* a_dst, bool a_tmpSave, bool a_ignoreINI) override;  // 02
		void    Unk_05() override;                                                                                // 05
		void    Unk_06() override;                                                                                // 06
		void    Unk_07() override;                                                                                // 07
		void    Unk_08() override;                                                                                // 08 - { return; }
		void    Unk_09() override;                                                                                // 09 - { return; }
		void    Unk_0C() override;                                                                                // 0C
		void    Unk_11() override;                                                                                // 11 - { return; }

		static BSWin32SaveDataSystemUtility* GetSingleton();
	};
	static_assert(sizeof(BSWin32SaveDataSystemUtility) == 0x228);
}
