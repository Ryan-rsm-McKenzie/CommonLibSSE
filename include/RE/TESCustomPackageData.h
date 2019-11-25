#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"
#include "RE/TESPackageData.h"


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
			UInt8			marker;				// 12 - XNAM
			UInt8			unk13;				// 13
			UInt32			unk14;				// 14
		};
		STATIC_ASSERT(sizeof(PackageData) == 0x18);


		struct DataInputs : public BSIntrusiveRefCounted
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


			// members
			UInt32				unk04;		// 04
			BSTArray<DataInput>	inputs;		// 08
		};
		STATIC_ASSERT(sizeof(DataInputs) == 0x20);


		virtual ~TESCustomPackageData();								// 00

		// override (TESPackageData)
		virtual void	Unk_01(void) override;							// 01
		virtual void	InitPackage(TESPackage* a_package) override;	// 03
		virtual void	Unk_04(void) override;							// 04 - { return; }
		virtual void	Unk_05(void) override;							// 05 - { return; }


		// members
		PackageData					packageData;		// 08
		BGSProcedureTreeBranch*		branches;			// 20
		BSTSmartPointer<DataInputs>	dataInputs;			// 28
		TESPackage*					packageTemplate;	// 30
		UInt16						versionCounter;		// 38
		bool						hasForceGreet;		// 3A
		UInt8						unk3B;				// 3B
		UInt32						unk3C;				// 3C
	};
	STATIC_ASSERT(sizeof(TESCustomPackageData) == 0x40);
}
