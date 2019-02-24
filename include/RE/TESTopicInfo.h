#pragma once

#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESTopicInfo : public TESForm
	{
	public:
		enum { kTypeID = FormType::Info };


		enum class FavorLevel : UInt8	// CNAM
		{
			kNone = 0,
			kSmall = 1,
			kMedium = 2,
			kLarge = 3
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct ResponseFlags	// ENAM
		{
			enum class Flag : UInt16
			{
				kNone = 0,
				kGoodbye = 1 << 0,
				kRandom = 1 << 1,
				kSayOnce = 1 << 2,
				kRandomEnd = 1 << 5,
				kInvisibleContinue = 1 << 6,
				kWalkAway = 1 << 7,
				kWalkAwayInvisibleInMenu = 1 << 8,
				kForceSubtitle = 1 << 9,
				kCanMoveWhileGreeting = 1 << 10,
				kNoLIPFile = 1 << 11,
				kRequiresPostProcessing = 1 << 12,
				kAudioOutputOverride = 1 << 13,
				kSpendsFavorPoints = 1 << 14,
			};


			float GetResetHours() const;


			Flag	flags;		// 0
			UInt16	resetHours;	// 2 - reset hours as a UInt16
		};


		virtual ~TESTopicInfo();	// 00


		// members
		TESTopic*		topic;				// 20
		TESTopicInfo*	previousInfo;		// 28 - PNAM
		Condition		conditions;			// 30 - CTDA
		UInt16			index;				// 38 - index in infoTopics array of parent topic
		UInt8			unk3A;				// 3A
		FavorLevel		favorLevel;			// 3B - CNAM
		ResponseFlags	responseFlags;		// 3C - ENAM
		UInt32			fileOffset;			// 40 - TESFile offset
		UInt32			pad44;				// 44
	};
	STATIC_ASSERT(sizeof(TESTopicInfo) == 0x48);
}
