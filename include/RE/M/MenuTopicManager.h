#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSDialogueBranch;
	class MenuOpenCloseEvent;
	class TESQuest;
	class TESTopic;
	class TESTopicInfo;
	struct PositionPlayerEvent;

	class MenuTopicManager :
		public BSTSingletonSDM<MenuTopicManager>,  // 0x10
		public BSTEventSink<MenuOpenCloseEvent>,   // 0x00
		public BSTEventSink<PositionPlayerEvent>   // 0x08
	{
	public:
		inline static constexpr auto RTTI = RTTI_MenuTopicManager;

		struct Dialogue
		{
		public:
			// members
			BSString						 topicText;		   // 00
			bool							 unk10;			   // 10
			bool							 unk11;			   // 11
			bool							 unk12;			   // 12 - data.topic->formID == 0xFD || data.topic->formID == 0x118
			std::uint8_t					 unk13;			   // 13
			std::uint32_t					 unk14;			   // 14
			BSSimpleList<DialogueResponse*>	 responses;		   // 18
			TESQuest*						 parentQuest;	   // 28
			TESTopicInfo*					 parentTopicInfo;  // 30
			TESTopic*						 parentTopic;	   // 38
			BSSimpleList<DialogueResponse*>* unk40;			   // 40
			std::uint8_t					 unk48;			   // 48
			bool							 neverSaid;		   // 49
			std::uint16_t					 unk4A;			   // 4A
			std::uint32_t					 unk4C;			   // 4C
			TESTopic*						 unk50;			   // 50
		};
		static_assert(sizeof(Dialogue) == 0x58);

		virtual ~MenuTopicManager();  // 00

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;	 // 01

		static MenuTopicManager* GetSingleton()
		{
			REL::Relocation<MenuTopicManager**> singleton{ REL::ID(514959) };
			return *singleton;
		}

		// members
		BSSimpleList<Dialogue*>*	 selectedResponseNode;	// 18
		BSSimpleList<Dialogue*>*	 dialogueList;			// 20
		std::uint64_t				 unk28;					// 28
		TESTopicInfo*				 rootTopicInfo;			// 30
		Dialogue*					 lastSelectedDialogue;	// 38
		WinAPI::CRITICAL_SECTION	 criticalSection;		// 40
		ObjectRefHandle				 speaker;				// 68
		ObjectRefHandle				 lastSpeaker;			// 6C - used if the dialogue menu was closed but the NPC is still talking
		TESTopicInfo*				 currentTopicInfo;		// 70 - only valid when the NPC is talking
		TESTopicInfo*				 lastTopicInfo;			// 78 - used if the dialogue menu was closed but the NPC is still talking
		BSTArray<BGSDialogueBranch*> blockingBranches;		// 80
		BSTArray<BGSDialogueBranch*> topLevelBranches;		// 98
		bool						 isGreetingPlayer;		// B0
		bool						 unkB1;					// B1
		bool						 isSayingGoodbye;		// B2
		bool						 unkB3;					// B3
		bool						 unkB4;					// B4
		bool						 unkB5;					// B5
		bool						 unkB6;					// B6
		bool						 unkB7;					// B7
		bool						 unkB8;					// B8
		bool						 unkB9;					// B9
		bool						 unkBA;					// BA
		bool						 unkBB;					// BB
		std::uint16_t				 padBC;					// BC
		BSTArray<TESTopic*>			 unkC0;					// C0
	};
	static_assert(sizeof(MenuTopicManager) == 0xD8);
}
