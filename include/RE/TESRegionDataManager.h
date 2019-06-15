#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESRegionDataManager


namespace RE
{
	class TESFile;
	class TESRegion;


	class TESRegionDataManager
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionDataManager;


		virtual ~TESRegionDataManager();									// 00

		// add
		virtual void	Unk_01(void);										// 01 - { return unk08; }
		virtual void	Unk_02(void);										// 02
		virtual void	Unk_03(void);										// 03
		virtual void	Unk_04(void);										// 04
		virtual void	Unk_05(void);										// 05
		virtual void	Unk_06(void);										// 06
		virtual void	Unk_07(void);										// 07
		virtual void	Unk_08(void);										// 08
		virtual bool	LoadRegion(TESFile* a_mod, TESRegion* a_region);	// 09


		// members
		TESRegion* unk08;	// 08
	};
	STATIC_ASSERT(sizeof(TESRegionDataManager) == 0x10);
}
