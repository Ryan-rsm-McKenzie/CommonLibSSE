#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSString.h"
#include "RE/BSTList.h"
#include "RE/MemoryManager.h"


namespace RE
{
	class Actor;
	class BGSSoundDescriptorForm;
	class ExtraSayToTopicInfo;
	class TESIdleForm;
	class TESQuest;
	class TESTopic;
	class TESTopicInfo;


	class DialogueData : public BSIntrusiveRefCounted
	{
	public:
		struct ResponseData
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


			// members
			BSString				responseText;	// 00
			EmotionType 			emotionType;	// 10
			UInt32 					emotionValue;	// 14
			BSFixedString			voiceFileName;	// 18
			TESIdleForm*			speakerIdle;	// 20
			TESIdleForm*			listenerIdle;	// 28
			BGSSoundDescriptorForm*	sound;			// 30
			Flag					flags;			// 38
			bool					hasLIPFile;		// 39
			UInt16					pad3A;			// 3A
			UInt32					pad3C;			// 3C
		};
		STATIC_ASSERT(sizeof(ResponseData) == 0x40);


		DialogueData(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker);
		~DialogueData() = default;

		TES_HEAP_REDEFINE_NEW();


		// members
		UInt32								pad04;				// 04
		BSSimpleList<ResponseData*>			responses;			// 08
		BSSimpleList<ResponseData*>::Node*	currentResponse;	// 18
		TESTopicInfo*						topicInfo;			// 20
		TESTopic*							topic;				// 28
		TESQuest*							quest;				// 30
		Actor*								speaker;			// 38
		ExtraSayToTopicInfo*				extraData;			// 40

	private:
		DialogueData* Ctor(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker);
	};
	STATIC_ASSERT(sizeof(DialogueData) == 0x48);
}
