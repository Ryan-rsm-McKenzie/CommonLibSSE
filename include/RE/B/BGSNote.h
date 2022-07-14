#pragma once

#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class BGSNote :
		public TESBoundObject,         // 00
		public TESModel,               // 30
		public TESFullName,            // 58
		public TESIcon,                // 68
		public BGSPickupPutdownSounds  // 78
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSNote;
		inline static constexpr auto VTABLE = VTABLE_BGSNote;
		inline static constexpr auto FORMTYPE = FormType::Note;

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kNoteRead = (std::uint32_t)1 << 31
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BGSNote() override;  // 00

		// override (TESBoundObject)
		void InitializeData() override;                                                                                                                                // 04
		void ClearData() override;                                                                                                                                     // 05
		bool Load(TESFile* a_mod) override;                                                                                                                            // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                              // 0F
		void Revert(BGSLoadFormBuffer* a_buf) override;                                                                                                                // 12
		void InitItemImpl() override;                                                                                                                                  // 13
		bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37

		// members
		TESTopic*               unk90;  // 90
		TESActorBase*           unk98;  // 98
		BSSimpleList<TESQuest*> unkA0;  // A0
		std::uint64_t           unkB0;  // B0
	};
	static_assert(sizeof(BGSNote) == 0xB8);
}
