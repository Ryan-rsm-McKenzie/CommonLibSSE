#pragma once

#include "RE/BGSBaseAlias.h"
#include "RE/BSPointerHandle.h"
#include "RE/FormTypes.h"
#include "RE/QuestEvents.h"


namespace RE
{
	class BGSLocationRefType;
	class TESBoundObject;
	class TESCondition;


	class BGSRefAlias : public BGSBaseAlias
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSRefAlias;


		struct ForcedFillData  // kForced
		{
			ObjectRefHandle forcedRef;	// 0 - ALFR
		};
		STATIC_ASSERT(sizeof(ForcedFillData) == 0x4);


		struct FromAliasFillData  // kFromAlias
		{
			UInt32				forcedFromAlias;  // 00 - ALFA
			UInt32				pad04;			  // 04
			BGSLocationRefType* forcedRefType;	  // 08 - ALRT
		};
		STATIC_ASSERT(sizeof(FromAliasFillData) == 0x10);


		struct FromEventFillData  // kFromEvent
		{
			QuestEvent forcedFromEvent;	 // ALFE
			UInt32	   forcedEventData;	 // ALFD
		};
		STATIC_ASSERT(sizeof(FromEventFillData) == 0x8);


		struct CreatedFillData	// kCreated
		{
			enum class Level : UInt16  // ALCL
			{
				kEasy = 0,
				kMedium = 1,
				kHard = 2,
				kVeryHard = 3,
				kNone = 4
			};


			struct Alias  // ALCA
			{
				enum class Create : UInt16
				{
					kAt = 0x0000,
					kIn = 0x8000
				};


				UInt16 alias;	// 0
				Create create;	// 2
			};
			STATIC_ASSERT(sizeof(Alias) == 0x4);


			TESBoundObject* object;	 // 00 - ALCO
			Alias			alias;	 // 08 - ALCA
			Level			level;	 // 0C - ALCL
			UInt16			pad0E;	 // 0E
		};
		STATIC_ASSERT(sizeof(CreatedFillData) == 0x10);


		struct FromExternalFillData	 // kFromExternal
		{
			TESQuest* externalQuest;  // 00 - ALEQ
			UInt32	  externalAlias;  // 08 - ALEA
			UInt32	  pad0C;		  // 0C
		};
		STATIC_ASSERT(sizeof(FromExternalFillData) == 0x10);


		struct UniqueActorFillData	// kUniqueActor
		{
			TESNPC* uniqueActor;  // 0 - ALUA
		};
		STATIC_ASSERT(sizeof(UniqueActorFillData) == 0x8);


		struct NearAliasFillData  // kNearAlias
		{
			enum class NEARFILLTYPE : UInt32
			{
				kLinkedChildren = 0,
				kLinkedParents = 1
			};


			UInt32		 nearAlias;		// 0 - ALNA
			NEARFILLTYPE nearFillType;	// 4 - ALNT
		};
		STATIC_ASSERT(sizeof(NearAliasFillData) == 0x8);


		union GenericFillData
		{
			struct Padding
			{
				UInt64 pad1;  // 00
				UInt64 pad2;  // 08
				UInt64 pad3;  // 10
			};
			STATIC_ASSERT(sizeof(Padding) == 0x18);


			~GenericFillData() {}


			// members
			Padding				 padding;
			ForcedFillData		 forced;
			FromAliasFillData	 fromAlias;
			FromEventFillData	 fromEvent;
			CreatedFillData		 created;
			FromExternalFillData fromExternal;
			UniqueActorFillData	 uniqueActor;
			NearAliasFillData	 nearAlias;
		};
		STATIC_ASSERT(sizeof(GenericFillData) == 0x18);


		virtual ~BGSRefAlias();	 // 00

		// override (BGSBaseAlias)
		virtual bool				 Load(TESFile* a_mod) override;		  // 01
		virtual void				 InitItem(TESForm* a_form) override;  // 02
		virtual const BSFixedString& QType() const override;			  // 03 - { return "Ref"; }


		// members
		GenericFillData fillData;	 // 28
		TESCondition*	conditions;	 // 40
	};
	STATIC_ASSERT(sizeof(BGSRefAlias) == 0x48);
}
