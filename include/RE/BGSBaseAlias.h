#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSBaseAlias

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // TESQuest


namespace RE
{
	class TESFile;


	class BGSBaseAlias
	{
	public:
		inline static const void* RTTI = RTTI_BGSBaseAlias;


		enum class FillType : UInt16
		{
			kNone = 0,
			kForcedReference = 1,
			kLocationAliasReference = 2,
			kFindMatchingReferenceFromEvent = 3,
			kCreateReferenceToObject = 4,
			kExternalAliasReference = 5,
			kUniqueActor = 6,
			kFindMatchingReferenceNearAlias = 7
		};


		struct AliasFlags	// FNAM
		{
			enum class Flag : UInt16
			{
				kNone = 0,
				kReservesLocationReference = 1 << 0,
				kOptional = 1 << 1,
				kQuestObject = 1 << 2,
				kAllowReuseInQuest = 1 << 3,
				kAllowDead = 1 << 4,
				kMatchingRef_InLoadedArea = 1 << 5,
				kEssential = 1 << 6,
				kAllowDisabled = 1 << 7,
				kStoresText = 1 << 8,
				kAllowReserved = 1 << 9,
				kProtected = 1 << 10,
				kForcedByAliases = 1 << 11,	// ?
				kAllowDestroyed = 1 << 12,
				kMatchingRef_Closest = 1 << 13,
				kUsesStoredText = 1 << 14,
				kInitiallyDisabled = 1 << 15
			};


			enum class AdditionalFlag : UInt16
			{
				kNone = 0,
				kAllowCleared = 1 << 0,
				kClearNamesWhenRemoved = 1 << 1
			};


			// members
			Flag			flags;				// 0
			AdditionalFlag	additionalFlags;	// 2
		};
		STATIC_ASSERT(sizeof(AliasFlags) == 0x4);


		virtual ~BGSBaseAlias();									// 00

		// add
		virtual bool					Load(TESFile* a_mod) = 0;	// 01
		virtual void					Unk_02(void) = 0;			// 02
		virtual const BSFixedString&	GetTypeString() const = 0;	// 03

		bool							IsQuestObject() const;


		// members
		BSFixedString	name;		// 08 - ALID
		TESQuest*		owner;		// 10
		UInt32			id;			// 18 - ALST/ALLS
		AliasFlags		aliasFlags;	// 1C - FNAM
		FillType		fillType;	// 20
		UInt16			unk22;		// 22
		UInt32			pad24;		// 24
	};
	STATIC_ASSERT(sizeof(BGSBaseAlias) == 0x28);
}
