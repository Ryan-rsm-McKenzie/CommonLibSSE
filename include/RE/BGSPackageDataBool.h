#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSPackageDataBool

#include "RE/BGSNamedPackageData.h"  // BGSNamedPackageData
#include "RE/IPackageData.h"  // IPackageData


namespace RE
{
	class BGSPackageDataBool : public BGSNamedPackageData<IPackageData>
	{
	public:
		inline static const void* RTTI = RTTI_BGSPackageDataBool;


		virtual ~BGSPackageDataBool();										// 00

		// override (BGSNamedPackageData<IPackageData>)
		virtual void	LoadPackage(TESFile* a_mod) override;				// 02
		virtual void	Assign(IPackageData* a_other) override;				// 03
		virtual bool	IsNotEqual(IPackageData* a_other) const override;	// 04
		virtual void	Unk_05(void) override;								// 05 - { return 1; }
		virtual void	Unk_07(void) override;								// 07
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;		// 08
		virtual void	Unk_09(void) override;								// 09 - { return; }
		virtual bool	GetDataAsString(BSString* a_dst) const override;	// 0A - { return a_dst.Set(((data >> 1) & 1 ? "True" : "False"), 0); }
		virtual void	Unk_0B(void) override;								// 0B
	};
	STATIC_ASSERT(offsetof(BGSPackageDataBool, data) == 0x08);
	STATIC_ASSERT(sizeof(BGSPackageDataBool) == 0x10);
}
