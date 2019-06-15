#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESCustomPackageData

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/TESPackageData.h"  // TESPackageData


namespace RE
{
	class BGSProcedureTreeBranch;
	class IPackageData;
	class TESPackage;


	class TESCustomPackageData : public TESPackageData
	{
	public:
		inline static const void* RTTI = RTTI_TESCustomPackageData;


		struct PackageData
		{
			IPackageData**	dataInputValues;	// 00
			UInt8*			dataInputs;			// 08
			UInt16			dataInputCount;		// 10
			UInt16			marker;				// 12 - XNAM
			UInt32			unk14;				// 14
		};
		STATIC_ASSERT(sizeof(PackageData) == 0x18);


		struct DataInputs
		{
			struct DataInput
			{
				enum class Flag : UInt8
				{
					kNone = 0,
					kPublic = 1 << 0
				};


				BSFixedString	name;	// 00 - BNAM
				UInt8			index;	// 08 - UNAM
				Flag			flags;	// 09 - PNAM
				UInt8			pad0A;	// 0A
				UInt8			pad0B;	// 0B
				UInt32			pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(DataInput) == 0x10);


			volatile UInt32		refCount;	// 00
			UInt32				unk04;		// 04
			BSTArray<DataInput>	inputs;		// 08
		};
		STATIC_ASSERT(sizeof(DataInputs) == 0x20);


		virtual ~TESCustomPackageData();		// 00

		// override (TESPackageData)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_03(void) override;	// 03
		virtual void	Unk_04(void) override;	// 04 - { return; }
		virtual void	Unk_05(void) override;	// 05 - { return; }


		// members
		PackageData				packageData;		// 08
		BGSProcedureTreeBranch*	branches;			// 20
		DataInputs*				dataInputs;			// 28
		TESPackage*				packageTemplate;	// 30
		UInt32					versionCounter;		// 38
		UInt32					unk3C;				// 3C
	};
	STATIC_ASSERT(sizeof(TESCustomPackageData) == 0x40);
}
