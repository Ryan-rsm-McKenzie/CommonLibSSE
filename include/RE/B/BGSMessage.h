#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSMessage :
		public TESForm,        // 00
		public TESFullName,    // 20
		public TESDescription  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMessage;
		inline static constexpr auto VTABLE = VTABLE_BGSMessage;
		inline static constexpr auto FORMTYPE = FormType::Message;

		enum class MessageFlag
		{
			kNone = 0,
			kMessageBox = 1 << 0,
			kInitialDelay = 1 << 1
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct MESSAGEBOX_BUTTON
		{
		public:
			// members
			BSFixedString text;        // 00 - ITXT
			TESCondition  conditions;  // 08
		};
		static_assert(sizeof(MESSAGEBOX_BUTTON) == 0x10);

		~BGSMessage() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BGSMenuIcon*                                 icon;         // 40 - INAM
		TESQuest*                                    ownerQuest;   // 48 - QNAM
		BSSimpleList<MESSAGEBOX_BUTTON*>             menuButtons;  // 50
		stl::enumeration<MessageFlag, std::uint32_t> flags;        // 60 - DNAM
		std::uint32_t                                displayTime;  // 64 - TNAM
	};
	static_assert(sizeof(BGSMessage) == 0x68);
}
