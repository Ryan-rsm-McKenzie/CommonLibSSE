#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSWin32SaveDataSystemUtility

#include "RE/BSSaveDataSystemUtility.h"  // BSSaveDataSystemUtility


namespace RE
{
	class BSWin32SaveDataSystemUtility : public BSSaveDataSystemUtility
	{
	public:
		inline static const void* RTTI = RTTI_BSWin32SaveDataSystemUtility;


		virtual ~BSWin32SaveDataSystemUtility();

		// override (BSSaveDataSystemUtility)
		virtual bool	CreateSaveDirectory(const char* a_pathName, bool a_ignoreINI) override;									// 01
		virtual errno_t	PrepareFileSavePath(const char* a_fileName, char* a_dst, bool a_tmpSave, bool a_ignoreINI) override;	// 02
		virtual void	Unk_05(void) override;																					// 05
		virtual void	Unk_06(void) override;																					// 06
		virtual void	Unk_07(void) override;																					// 07
		virtual void	Unk_08(void) override;																					// 08 - { return; }
		virtual void	Unk_09(void) override;																					// 09 - { return; }
		virtual void	Unk_0C(void) override;																					// 0C
		virtual void	Unk_11(void) override;																					// 11 - { return; }


		static BSWin32SaveDataSystemUtility* GetSingleton();
	};
	STATIC_ASSERT(sizeof(BSWin32SaveDataSystemUtility) == 0x228);
}
