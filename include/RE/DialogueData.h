#pragma once

#include "skse64/GameTypes.h"  // BSString

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // TESIdleForm, TESTopicInfo, TESTopic, TESQuest, Actor


namespace RE
{
	struct DialogueData
	{
		struct ResponseData
		{
			// members
			BSString				responseText;	// 00
			UInt32 					emotionType;	// 10
			UInt32 					emotionValue;	// 14
			BSFixedString			voiceFileName;	// 18
			TESIdleForm*			idleSpeaker;	// 20
			TESIdleForm*			idleListener;	// 28
			BGSSoundDescriptorForm*	sound;			// 30
			UInt8					unk38;			// 38
			UInt8					unk39;			// 39
			UInt16					pad3A;			// 3A
			UInt32					pad3C;			// 3C
		};
		STATIC_ASSERT(sizeof(ResponseData) == 0x40);


		// members
		BSSimpleList<ResponseData*>				dataList;	// 00
		BSSimpleList<ResponseData >::iterator	current;	// 10
		TESTopicInfo*							topicInfo;	// 18
		TESTopic*								topic;		// 20
		TESQuest*								quest;		// 28
		Actor*									speaker;	// 30
	};
	STATIC_ASSERT(sizeof(DialogueData) == 0x38);
}
