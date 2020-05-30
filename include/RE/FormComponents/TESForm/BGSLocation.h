#pragma once

#include "RE/BGSKeywordForm.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTTuple.h"
#include "RE/FormTypes.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class QueuedPromoteLocationReferencesTask;


	struct UnloadedRefData
	{
		union CellKey
		{
			BSTTuple<SInt16, SInt16> xy;
			UInt32					 raw;
		};
		STATIC_ASSERT(sizeof(CellKey) == 0x4);


		FormID	refID;			// 0
		FormID	parentSpaceID;	// 4
		CellKey cellKey;		// 8
	};
	STATIC_ASSERT(sizeof(UnloadedRefData) == 0xC);


	struct SpecialRefData  // LCSR
	{
		BGSLocationRefType* type;	  // 00
		UnloadedRefData		refData;  // 08
		UInt32				pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(SpecialRefData) == 0x18);


	struct UniqueNPCData  // LCUN
	{
		Actor*		 actor;		 // 00
		FormID		 refID;		 // 08
		UInt32		 pad0C;		 // 0C
		BGSLocation* editorLoc;	 // 10
	};
	STATIC_ASSERT(sizeof(UniqueNPCData) == 0x18);


	struct OverrideData
	{
		BSTArray<UnloadedRefData> addedData;	// 00 - ACPR
		BSTSet<FormID>			  removedData;	// 18 - RCPR
	};
	STATIC_ASSERT(sizeof(OverrideData) == 0x48);


	class BGSLocation :
		public TESForm,		   // 00
		public TESFullName,	   // 20
		public BGSKeywordForm  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLocation;
		inline static constexpr auto FORMTYPE = FormType::Location;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kKeywordData = 1 << 30,
				kCleared = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCleared = (UInt32)1 << 31
			};
		};


		struct KEYWORD_DATA
		{
			BGSKeyword* keyword;  // 00
			float		data;	  // 08
			UInt32		pad0C;	  // 0C
		};
		STATIC_ASSERT(sizeof(KEYWORD_DATA) == 0x10);


		virtual ~BGSLocation();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;					   // 04
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual bool FindInFileFast(TESFile* a_mod) override;	   // 0C
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;	   // 12
		virtual void InitItemImpl() override;					   // 13

		bool IsCleared() const;
		bool IsChild(const BGSLocation* a_possibleChild) const;
		bool IsParent(const BGSLocation* a_possibleParent) const;
		bool IsLoaded() const;


		// members
		BGSLocation*								   parentLoc;				// 48 - PNAM
		TESFaction*									   unreportedCrimeFaction;	// 50 - FNAM
		BGSMusicType*								   musicType;				// 58 - NAM1
		ObjectRefHandle								   worldLocMarker;			// 60 - MNAM
		float										   worldLocRadius;			// 64 - RNAM
		ObjectRefHandle								   horseLocMarker;			// 68 - NAM0
		UInt32										   pad6C;					// 6C
		BSTArray<SpecialRefData>					   specialRefs;				// 70 - LCSR
		BSTArray<UniqueNPCData>						   uniqueNPCs;				// 88 - LCUN
		OverrideData*								   overrideData;			// A0
		NiPointer<QueuedPromoteLocationReferencesTask> promoteRefsTask;			// A8
		BSTArray<ObjectRefHandle>					   promotedRefs;			// B0
		volatile SInt32								   loadedCount;				// C8
		UInt32										   fileOffset;				// CC
		BSTArray<KEYWORD_DATA>						   keywordData;				// D0
		UInt32										   lastChecked;				// E8
		bool										   cleared;					// EC
		bool										   everCleared;				// ED
		UInt16										   padEE;					// EE
	};
	STATIC_ASSERT(sizeof(BGSLocation) == 0xF0);
}
