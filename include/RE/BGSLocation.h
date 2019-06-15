#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSLocation

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


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


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCleared = static_cast<RecordFlag>(1 << 31)
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
		virtual void	InitDefaults() override;						// 04
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	Unk_0C(void) override;							// 0C
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13

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
		UInt32									unkCC;							// CC - used in Unk_0C()
		BSTArray<void*>							unkD0;							// D0 - used in Unk_12()
		UInt32									unkE8;							// E8
		bool									isCleared;						// EC - used in Unk_12()
		UInt8									unkED;							// ED
		UInt16									unkEE;							// EE
	};
	STATIC_ASSERT(sizeof(BGSLocation) == 0xF0);
}
