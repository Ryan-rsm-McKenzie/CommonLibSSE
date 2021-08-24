#pragma once

#include "RE/B/BSAudioManagerThread.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class BSISoundDescriptor;
	class BSXAudio2GameSound;
	struct BSSoundHandle;

	class BSAudioManager
	{
	public:
		static BSAudioManager* GetSingleton();

		bool Play(FormID a_soundFormID);
		bool Play(BSISoundDescriptor* a_descriptor);
		bool BuildSoundDataFromDescriptor(BSSoundHandle& a_soundHandle, BSISoundDescriptor* a_descriptor, std::uint32_t a_flags = 0x1A);
		void BuildSoundDataFromEditorID(BSSoundHandle& a_soundHandle, const char* a_editorID, std::uint32_t a_flags);

		// members
		std::uint64_t                                  unk000;  // 000
		void*                                          unk008;  // 008
		void*                                          unk010;  // 010
		void*                                          unk018;  // 018
		void*                                          unk020;  // 020
		std::uint64_t                                  unk028;  // 028
		BSTHashMap<std::uint32_t, BSXAudio2GameSound*> unk030;  // 030
		BSTHashMap<UnkKey, UnkValue>                   unk060;  // 060
		BSTHashMap<UnkKey, UnkValue>                   unk090;  // 090
		BSTHashMap<UnkKey, UnkValue>                   unk0C0;  // 0C0
		std::uint64_t                                  unk0F0;  // 0F0
		BSAudioManagerThread*                          unk0F8;  // 0F8
		std::uint64_t                                  unk100;  // 100
		BSFixedString                                  unk108;  // 108
		std::uint64_t                                  unk110;  // 110
		std::uint64_t                                  unk118;  // 118
		std::uint64_t                                  unk120;  // 120
		std::uint64_t                                  unk128;  // 128
		std::uint64_t                                  unk130;  // 130
		std::uint64_t                                  unk138;  // 138
		std::uint64_t                                  unk140;  // 140
		std::uint64_t                                  unk148;  // 148
		std::uint64_t                                  unk150;  // 150
		std::uint64_t                                  unk158;  // 158
		std::uint64_t                                  unk160;  // 160
		std::uint64_t                                  unk168;  // 168
		std::uint64_t                                  unk170;  // 170
		std::uint64_t                                  unk178;  // 178
		std::uint64_t                                  unk180;  // 180
		std::uint64_t                                  unk188;  // 188
	};
	static_assert(sizeof(BSAudioManager) == 0x190);
}
