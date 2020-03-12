#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	class TESFile;
	class TESForm;
	class TESQuest;


	class BGSBaseAlias
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBaseAlias;


		enum class FLAGS : UInt32
		{
			kNone = 0,
			kReserves = 1 << 0,
			kOptional = 1 << 1,
			kQuestObject = 1 << 2,
			kAllowReuse = 1 << 3,
			kAllowDead = 1 << 4,
			kLoadedOnly = 1 << 5,
			kEssential = 1 << 6,
			kAllowDisabled = 1 << 7,
			kStoreName = 1 << 8,
			kAllowReserved = 1 << 9,
			kProtected = 1 << 10,
			kForcedFromAlias = 1 << 11,
			kAllowDestroyed = 1 << 12,
			kFindPlayerClosest = 1 << 13,
			kUsesNames = 1 << 14,
			kInitiallyDisabled = 1 << 15,
			kAllowCleared = 1 << 16,
			kClearNameOnRemove = 1 << 17,
			kActorsOnly = 1 << 18,
			kTransient = 1 << 19,
			kExternalLink = 1 << 20,
			kNoPickpocket = 1 << 21,
			kDataAlias = 1 << 22,
			kSceneOptional = 1 << 24,
			kCreateIn = (UInt32)1 << 31	 // BGSRefAlias
		};


		enum class FILL_TYPE : UInt16  // BGSRefAlias
		{
			kConditions = 0,
			kForced = 1,
			kFromAlias = 2,
			kFromEvent = 3,
			kCreated = 4,
			kFromExternal = 5,
			kUniqueActor = 6,
			kNearAlias = 7
		};


		virtual ~BGSBaseAlias();  // 00

		// add
		virtual bool				 Load(TESFile* a_mod) = 0;		 // 01
		virtual void				 InitItem(TESForm* a_form) = 0;	 // 02
		virtual const BSFixedString& QType() const = 0;				 // 03

		const BSFixedString& GetTypeString() const;
		bool				 IsQuestObject() const;


		// members
		BSFixedString aliasName;	// 08 - ALID
		TESQuest*	  owningQuest;	// 10
		UInt32		  aliasID;		// 18 - ALST/ALLS
		FLAGS		  flags;		// 1C - FNAM
		FILL_TYPE	  fillType;		// 20
		UInt16		  pad22;		// 22
		UInt32		  pad24;		// 24
	};
	STATIC_ASSERT(sizeof(BGSBaseAlias) == 0x28);
}
