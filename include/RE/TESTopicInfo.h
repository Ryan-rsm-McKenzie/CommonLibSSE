#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESTopicInfo

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class TESTopicInfo : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESTopicInfo;


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
			SInt16	resetHours;	// 2 - reset hours as a SInt16
		};
		STATIC_ASSERT(sizeof(ResponseFlags) == 0x4);


		struct ResponseData	// TRDT
		{
			enum class EmotionType : UInt32
			{
				kNeutral = 0,
				kAnger = 1,
				kDisgust = 2,
				kFear = 3,
				kSad = 4,
				kHappy = 5,
				kSurprise = 6,
				kPuzzled = 7
			};


			enum class Flag : UInt8
			{
				kNone = 0,
				kUseEmotionAnimation = 1 << 0
			};


			~ResponseData();

			TES_HEAP_REDEFINE_NEW();


			// members
			EmotionType				emotionType;	// 00
			UInt32					emotionValue;	// 04
			TESTopic*				unk08;			// 08
			UInt8					responseNumber;	// 10
			UInt8					pad11;			// 11
			UInt16					pad12;			// 12
			UInt32					pad14;			// 14
			BGSSoundDescriptorForm*	sound;			// 18
			Flag					flags;			// 20
			UInt8					pad21;			// 21
			UInt16					pad22;			// 22
			UInt32					pad24;			// 24
			BSFixedString			responseText;	// 28 - NAM1
			TESIdleForm*			speakerIdle;	// 30
			TESIdleForm*			listenerIdle;	// 38
			ResponseData*			next;			// 40
		};
		STATIC_ASSERT(sizeof(ResponseData) == 0x48);


		virtual ~TESTopicInfo();											// 00

		// override (TESForm)
		virtual void	InitDefaults() override;							// 04
		virtual void	ReleaseManagedData() override;						// 05
		virtual bool	LoadForm(TESFile* a_mod) override;					// 06
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;		// 0F
		virtual void	Unk_12(void) override;								// 12
		virtual void	InitItem() override;								// 13
		virtual void	GetFormDesc(char* a_buf, UInt32 a_bufLen) override;	// 16 - { return; }
		virtual void	SetFlag00000002(bool a_set) override;				// 24
		virtual void	Unk_30(void) override;								// 30
		virtual void	Unk_31(void) override;								// 31


		// members
		TESTopic*		topic;			// 20
		TESTopicInfo*	previousInfo;	// 28 - PNAM
		Condition		conditions;		// 30 - CTDA
		SInt16			index;			// 38 - index in infoTopics array of parent topic
		bool			unk3A;			// 3A
		FavorLevel		favorLevel;		// 3B - CNAM
		ResponseFlags	responseFlags;	// 3C - ENAM
		UInt32			fileOffset;		// 40 - TESFile offset
		UInt32			pad44;			// 44
	};
	STATIC_ASSERT(sizeof(TESTopicInfo) == 0x48);
}
