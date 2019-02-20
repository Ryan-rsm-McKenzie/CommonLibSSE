#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType, TESQuest


namespace RE
{
	class TESFile;


	class BGSBaseAlias
	{
	public:
		enum { kTypeID = FormType::Alias };


		enum class Flag : UInt32	// FNAM
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
			kAlloReserved = 1 << 9,
			kProtected = 1 << 10,
			kForcedByAliases = 1 << 11,	// ?
			kAllowDestroyed = 1 << 12,
			kMatchingRef_Closest = 1 << 13,
			kUsesStoredText = 1 << 14,
			kInitiallyDisabled = 1 << 15
		};


		virtual ~BGSBaseAlias();									// 00

		// add
		virtual bool					Load(TESFile* a_mod) = 0;	// 01
		virtual void					Unk_02(void);				// 02 - pure
		virtual const BSFixedString&	GetTypeString() const = 0;	// 03

		bool							IsQuestObject() const;


		// members
		BSFixedString	name;	// 08 - ALID
		TESQuest*		owner;	// 10
		UInt32			id;		// 18 - ALST
		Flag			flags;	// 1C - FNAM
		UInt64			unk20;	// 20
	};
	STATIC_ASSERT(sizeof(BGSBaseAlias) == 0x28);
}
