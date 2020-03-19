#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"
#include "RE/TESPackageData.h"


namespace RE
{
	class IPackageData;
	class IProcedureTreeItem;
	class TESPackage;


	struct BGSPackageDataList
	{
		IPackageData** data;	  // 00
		SInt8*		   uids;	  // 08
		UInt16		   dataSize;  // 10
		SInt8		   nextUID;	  // 12 - XNAM
		UInt8		   pad13;	  // 13
		UInt32		   pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(BGSPackageDataList) == 0x18);


	struct BGSPackageDataNameMap : public BSIntrusiveRefCounted
	{
	public:
		struct NameMapData
		{
		public:
			enum class Flag : UInt8
			{
				kNone = 0,
				kPublic = 1 << 0
			};


			// members
			BSFixedString name;		 // 00 - BNAM
			SInt8		  uid;		 // 08 - UNAM
			bool		  isPublic;	 // 09 - PNAM
			UInt8		  pad0A;	 // 0A
			UInt8		  pad0B;	 // 0B
			UInt32		  pad0C;	 // 0C
		};
		STATIC_ASSERT(sizeof(NameMapData) == 0x10);


		// members
		UInt32				  pad04;	// 04
		BSTArray<NameMapData> nameMap;	// 08
	};
	STATIC_ASSERT(sizeof(BGSPackageDataNameMap) == 0x20);


	class TESCustomPackageData : public TESPackageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCustomPackageData;


		virtual ~TESCustomPackageData();  // 00

		// override (TESPackageData)
		virtual void Copy(TESPackageData* a_package, TESForm* a_form) override;	 // 01
		virtual void InitItem(TESForm* a_form) override;						 // 03
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;				 // 04 - { return; }
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;				 // 05 - { return; }


		// members
		BGSPackageDataList					   data;					 // 08
		IProcedureTreeItem*					   procedureTree;			 // 20
		BSTSmartPointer<BGSPackageDataNameMap> nameMap;					 // 28
		TESPackage*							   templateParent;			 // 30
		UInt16								   version;					 // 38
		bool								   alwaysRecheckConditions;	 // 3A
		UInt8								   pad3B;					 // 3B
		UInt32								   pad3C;					 // 3C
	};
	STATIC_ASSERT(sizeof(TESCustomPackageData) == 0x40);
}
