#pragma once

#include "RE/BGSKeywordForm.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class BGSLocation :
		public TESForm,			// 00
		public TESFullName,		// 20
		public BGSKeywordForm	// 30
	{
	public:
		inline static const void* RTTI = RTTI_BGSLocation;


		enum { kTypeID = FormType::Location };


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


		struct LocationCellStaticReference	// LCSR
		{
			BGSLocationRefType*	locRefType;	// 00
			FormID				marker;		// 08
			FormID				location;	// 0C
			SInt16				gridY;		// 10
			SInt16				gridX;		// 12
			UInt32				pad14;		// 14
		};
		STATIC_ASSERT(sizeof(LocationCellStaticReference) == 0x18);


		struct LocationCellUnique	// LCUN
		{
			Actor*			actor;		// 00
			FormID			ref;		// 18
			UInt32			pad1C;		// 1C
			BGSLocation*	location;	// 1C
		};
		STATIC_ASSERT(sizeof(LocationCellUnique) == 0x18);


		struct PersistentReferences
		{
			struct ActorCell	// ACPR
			{
				FormID	actor;	// 00
				FormID	cell;	// 04
				SInt16	gridY;	// 08
				SInt16	gridX;	// 0A
			};
			STATIC_ASSERT(sizeof(ActorCell) == 0xC);


			BSTArray<ActorCell>			actorCells;		// 00 - ACPR
			BSTHashMap<FormID, UInt32>	referenceCells;	// 18 - RCPR - key maps to nothing, used to test existence
		};
		STATIC_ASSERT(sizeof(PersistentReferences) == 0x48);


		virtual ~BGSLocation();											// 00

		// override (TESForm)
		virtual void	InitializeData() override;						// 04
		virtual bool	Load(TESFile* a_mod) override;					// 06
		virtual bool	FindInFileFast(TESFile* a_mod) override;		// 0C
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	InitItemImpl() override;						// 13

		bool			IsCleared() const;
		bool			IsChild(const BGSLocation* a_possibleChild) const;
		bool			IsParent(const BGSLocation* a_possibleParent) const;
		bool			IsLoaded() const;


		// members
		BGSLocation*							parentLocation;					// 48 - PNAM
		TESFaction*								unreportedCrimeFaction;			// 50 - FNAM
		BGSMusicType*							music;							// 58 - NAM1
		RefHandle								worldLocationMarkerRef;			// 60 - MNAM
		float									worldLocationRadius;			// 64 - RNAM
		RefHandle								horseMarkerRef;					// 68 - NAM0
		UInt32									pad6C;							// 6C
		BSTArray<LocationCellStaticReference>	locationCellStaticReferences;	// 70 - LCSR
		BSTArray<LocationCellUnique>			locationCellUniques;			// 88 - LCUN
		PersistentReferences*					persistentReferences;			// A0
		UInt64									unkA8;							// A8
		BSTArray<void*>							unkB0;							// B0
		UInt32									loadedState;					// C8
		UInt32									fileOffset;						// CC
		BSTArray<void*>							unkD0;							// D0
		UInt32									unkE8;							// E8
		bool									isCleared;						// EC
		UInt8									unkED;							// ED
		UInt16									unkEE;							// EE
	};
	STATIC_ASSERT(sizeof(BGSLocation) == 0xF0);
}
