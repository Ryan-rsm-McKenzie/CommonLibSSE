#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSRefAlias

#include "RE/BGSBaseAlias.h"  // BGSBaseAlias
#include "RE/FormTypes.h"  // TESNPC, TESObjectSTAT, TESQuest, BGSLocation
#include "RE/QuestEvents.h"  // QuestEvent


namespace RE
{
	class Condition;


	class BGSRefAlias : public BGSBaseAlias
	{
	public:
		inline static const void* RTTI = RTTI_BGSRefAlias;


		union FillData
		{
			struct LocationAliasReference
			{
				UInt32			alias;		// 00 - ALFA
				UInt32			pad04;		// 04
				BGSLocation*	refType;	// 08 - ALRT
			};
			STATIC_ASSERT(sizeof(LocationAliasReference) == 0x10);


			struct ReferenceFromEvent
			{
				QuestEvent	fromEvent;	// ALFE
				UInt32		eventData;	// ALFD
			};
			STATIC_ASSERT(sizeof(ReferenceFromEvent) == 0x8);


			struct ReferenceToObject
			{
				enum class Level : UInt16	// ALCL
				{
					kEasy = 0,
					kMedium = 1,
					kHard = 2,
					kVeryHard = 3,
					kNone = 4
				};


				struct Alias	// ALCA
				{
					enum class Create : UInt16
					{
						kAt = 0x0000,
						kIn = 0x8000
					};


					UInt16	alias;	// 0
					Create	create;	// 2
				};
				STATIC_ASSERT(sizeof(Alias) == 0x4);


				TESObjectSTAT*	object;	// 00 - ALCO
				Alias			alias;	// 08 - ALCA
				Level			level;	// 0C - ALCL
				UInt16			pad0E;	// 0E
			};
			STATIC_ASSERT(sizeof(ReferenceToObject) == 0x10);


			struct ExternalAliasReference
			{
				TESQuest*	quest;	// 00 - ALEQ
				UInt32		alias;	// 08 - ALEA
				UInt32		pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(ExternalAliasReference) == 0x10);


			struct ReferenceNearAlias
			{
				enum class Type : UInt32
				{
					kLinkedRefChild = 0
				};


				UInt32	alias;	// 0 - ALNA
				Type	type;	// 4 - ALNT
			};
			STATIC_ASSERT(sizeof(ReferenceNearAlias) == 0x8);


			// members
			RefHandle				forcedRef;			// ALFR - kForcedReference
			LocationAliasReference	locationAliasRef;	// kLocationAliasReference
			ReferenceFromEvent		refFromEvent;		// kFindMatchingReferenceFromEvent
			ReferenceToObject		refToObject;		// kCreateReferenceToObject
			ExternalAliasReference	externalAliasRef;	// kExternalAliasReference
			TESNPC*					uniqueActor;		// ALUA - kUniqueActor
			ReferenceNearAlias		refNearAlias;		// kFindMatchingReferenceNearAlias
		};
		STATIC_ASSERT(sizeof(FillData) == 0x10);


		virtual ~BGSRefAlias();											// 00

		// override (BGSBaseAlias)
		virtual bool					Load(TESFile* a_mod) override;	// 01
		virtual void					Unk_02(void) override;			// 02
		virtual const BSFixedString&	GetTypeString() const override;	// 03 - { return "Ref"; }


		// members
		FillData	fillData;	// 28
		UInt64		unk38;		// 38
		Condition*	conditions;	// 40
	};
	STATIC_ASSERT(sizeof(BGSRefAlias) == 0x48);
}
