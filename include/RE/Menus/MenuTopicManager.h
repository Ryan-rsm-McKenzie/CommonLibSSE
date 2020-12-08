#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTList.h"
#include "RE/BSCore/BSTSingleton.h"


namespace RE
{
	class BGSDialogueBranch;
	class DialoguePackage;
	class MenuEventHandler;
	class MenuOpenCloseEvent;
	class TESQuest;
	class TESTopic;
	class TESTopicInfo;
	struct PositionPlayerEvent;


	class MenuTopicManager :
		public BSTSingletonSDM<MenuTopicManager>,
		public BSTEventSink<MenuOpenCloseEvent>,
		public BSTEventSink<PositionPlayerEvent>
	{
	public:
		inline static constexpr auto RTTI = RTTI_MenuTopicManager;


		struct Dialogue
		{
		public:
			struct Data
			{
			public:
				// members
				BSSimpleList<BSString*> responses;	  // 00
				TESQuest*				parentQuest;  // 10
				TESTopicInfo*			topicInfo;	  // 18
				TESTopic*				topic;		  // 20
				Data*					unk28;		  // 28
				std::uint8_t			unk30;		  // 30
				bool					neverSaid;	  // 31
				std::uint16_t			unk32;		  // 32
				std::uint32_t			unk34;		  // 34
				TESTopic*				unk38;		  // 38
			};
			static_assert(sizeof(Data) == 0x40);


			// members
			BSString	  topicText;  // 00
			bool		  unk10;	  // 10
			bool		  unk11;	  // 11
			bool		  unk12;	  // 12 - data.topic->formID == 0xFD || data.topic->formID == 0x118
			std::uint8_t  unk13;	  // 13
			std::uint32_t unk14;	  // 14
			Data		  data;		  // 18
		};
		static_assert(sizeof(Dialogue) == 0x58);


		virtual ~MenuTopicManager();  // 00

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;	 // 01


		static MenuTopicManager* GetSingleton();


		// members
		BSSimpleList<Dialogue*>*	 unk18;				  // 18
		BSSimpleList<Dialogue*>*	 dialogueList;		  // 20
		std::uint64_t				 unk28;				  // 28
		TESTopicInfo*				 unk30;				  // 30
		Dialogue*					 currentDialogue;	  // 38
		CRITICAL_SECTION			 criticalSection;	  // 40
		RefHandle					 dialogueTarget;	  // 68
		RefHandle					 lastDialogueTarget;  // 6C - used if the dialogue menu was closed but the NPC is still talking
		TESTopicInfo*				 currentTopicInfo;	  // 70 - only valid when the NPC is talking
		TESTopicInfo*				 lastTopicInfo;		  // 78 - used if the dialogue menu was closed but the NPC is still talking
		BSTArray<BGSDialogueBranch*> blockingBranches;	  // 80
		BSTArray<BGSDialogueBranch*> topLevelBranches;	  // 98
		bool						 unkB0;				  // B0
		bool						 unkB1;				  // B1
		bool						 unkB2;				  // B2
		bool						 unkB3;				  // B3
		bool						 unkB4;				  // B4
		bool						 unkB5;				  // B5
		bool						 unkB6;				  // B6
		bool						 unkB7;				  // B7
		bool						 unkB8;				  // B8
		bool						 unkB9;				  // B9
		bool						 unkBA;				  // BA
		bool						 unkBB;				  // BB
		std::uint16_t				 padBC;				  // BC
		BSTArray<TESTopic*>			 unkC0;				  // C0
	};
	static_assert(sizeof(MenuTopicManager) == 0xD8);
}
