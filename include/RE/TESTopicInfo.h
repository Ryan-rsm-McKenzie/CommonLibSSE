#pragma once

#include "RE/BSFixedString.h"
#include "RE/DialogueItem.h"
#include "RE/FormTypes.h"
#include "RE/MemoryManager.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"


namespace RE
{
	struct TOPIC_INFO_DATA	// ENAM
	{
		enum class TOPIC_INFO_FLAGS : UInt16
		{
			kNone = 0,
			kStartSceneOnEnd = 1 << 0,
			kRandom = 1 << 1,
			kSayOnce = 1 << 2,
			kRequiresPlayerActivation = 1 << 3,
			kInfoRefusal = 1 << 4,
			kRandomEnd = 1 << 5,
			kEndRunningScene = 1 << 6,
			kIsForceGreet = 1 << 7,
			kPlayerAddress = 1 << 8,
			kForceSubtitle = 1 << 9,
			kCanMoveWhileGreeting = 1 << 10,
			kNoLIPFile = 1 << 11,
			kPostProcess = 1 << 12,
			kCustomSoundOutput = 1 << 13,
			kSpendsFavorPoints = 1 << 14
		};


		float GetResetHours() const;


		TOPIC_INFO_FLAGS flags;			  // 0
		UInt16			 timeUntilReset;  // 2 - reset hours as a UInt16
	};
	STATIC_ASSERT(sizeof(TOPIC_INFO_DATA) == 0x4);


	class TESTopicInfo : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTopicInfo;
		inline static constexpr auto FORMTYPE = FormType::Info;


		enum class FavorLevel : UInt8  // CNAM
		{
			kNone = 0,
			kSmall = 1,
			kMedium = 2,
			kLarge = 3
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kSaidOnce = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct ResponseData	 // TRDT
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
			EmotionType				emotionType;	 // 00
			UInt32					emotionValue;	 // 04
			TESTopic*				unk08;			 // 08
			UInt8					responseNumber;	 // 10
			UInt8					pad11;			 // 11
			UInt16					pad12;			 // 12
			UInt32					pad14;			 // 14
			BGSSoundDescriptorForm* sound;			 // 18
			Flag					flags;			 // 20
			UInt8					pad21;			 // 21
			UInt16					pad22;			 // 22
			UInt32					pad24;			 // 24
			BSFixedString			responseText;	 // 28 - NAM1
			TESIdleForm*			speakerIdle;	 // 30
			TESIdleForm*			listenerIdle;	 // 38
			ResponseData*			next;			 // 40
		};
		STATIC_ASSERT(sizeof(ResponseData) == 0x48);


		virtual ~TESTopicInfo();  // 00

		// override (TESForm)
		virtual void InitializeData() override;															   // 04
		virtual void ClearData() override;																   // 05
		virtual bool Load(TESFile* a_mod) override;														   // 06
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;										   // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;											   // 12
		virtual void InitItemImpl() override;															   // 13
		virtual void GetFormDetailedString(char* a_buf, UInt32 a_bufLen) override;						   // 16 - { return; }
		virtual void SetAltered(bool a_set) override;													   // 24
		virtual bool BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;  // 30
		virtual void CreateGroupData(FORM* a_form, FORM_GROUP* a_group) override;						   // 31

		DialogueItem GetDialogueData(Actor* a_speaker);


		// members
		TESTopic*		parentTopic;	// 20
		TESTopicInfo*	dataInfo;		// 28 - PNAM
		TESCondition	objConditions;	// 30 - CTDA
		UInt16			infoIndex;		// 38 - index in infoTopics array of parent topic
		bool			saidOnce;		// 3A
		FavorLevel		favorLevel;		// 3B - CNAM
		TOPIC_INFO_DATA data;			// 3C - ENAM
		UInt32			fileOffset;		// 40
		UInt32			pad44;			// 44
	};
	STATIC_ASSERT(sizeof(TESTopicInfo) == 0x48);
}
