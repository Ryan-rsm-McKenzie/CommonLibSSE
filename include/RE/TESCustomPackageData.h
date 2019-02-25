#pragma once

#include "RE/TESPackageData.h"  // TESPackageData


namespace RE
{
	class TESCustomPackageData : public TESPackageData
	{
	public:
		virtual ~TESCustomPackageData();		// 00

		// override (TESPackageData)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_03(void) override;	// 03
		virtual void	Unk_04(void) override;	// 04 - { return; }
		virtual void	Unk_05(void) override;	// 05 - { return; }


		// members
		UInt64	unk08;	// 08
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
	};
	STATIC_ASSERT(sizeof(TESCustomPackageData) == 0x40);
}
