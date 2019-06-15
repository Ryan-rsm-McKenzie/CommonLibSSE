#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IPackageData


namespace RE
{
	class BGSLoadFormBuffer;
	class BSString;
	class TESFile;


	class IPackageData
	{
	public:
		inline static const void* RTTI = RTTI_IPackageData;


		virtual ~IPackageData();										// 00

		// add
		virtual void	SwapFormIDForRefHandle() = 0;					// 01
		virtual void	LoadPackage(TESFile* a_mod) = 0;				// 02
		virtual void	Assign(IPackageData* a_other) = 0;				// 03
		virtual bool	IsNotEqual(IPackageData* a_other) const = 0;	// 04
		virtual void	Unk_05(void) = 0;								// 05
		virtual void	Unk_06(void);									// 06 - { return; }
		virtual void	Unk_07(void);									// 07 - { return; }
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf);			// 08 - { return; }
		virtual void	Unk_09(void);									// 09 - { return; }
		virtual bool	GetDataAsString(BSString* a_dst) const = 0;		// 0A
		virtual void	Unk_0B(void) = 0;								// 0B
		virtual void	Unk_0C(void);									// 0C - { return 0; }
	};
	STATIC_ASSERT(sizeof(IPackageData) == 0x8);
}
