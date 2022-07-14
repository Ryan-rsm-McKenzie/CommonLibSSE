#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESPackage.h"

namespace RE
{
	class DialoguePackage : public TESPackage
	{
	public:
		inline static constexpr auto RTTI = RTTI_DialoguePackage;
		inline static constexpr auto VTABLE = VTABLE_DialoguePackage;
		inline static constexpr auto FORMTYPE = FormType::Package;

		~DialoguePackage() override;  // 00

		// override (TESPackage)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;      // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;      // 0F
		void InitLoadGame(BGSLoadFormBuffer* a_buf) override;  // 10 - { TESForm::InitLoadGame(a_buf); }
		void Copy(TESForm* a_srcForm) override;                // 2F - { TESForm::Copy(a_srcForm); }
		bool IsPackageOwner(Actor* a_actor) override;          // 3F

		// members
		std::uint32_t   unk0E0;  // 0E0
		ObjectRefHandle unk0E4;  // 0E4
		ActorHandle     unk0E8;  // 0E8
		ActorHandle     unk0EC;  // 0EC
		std::uint64_t   unk0F0;  // 0F0
		std::uint64_t   unk0F8;  // 0F8
	};
	static_assert(sizeof(DialoguePackage) == 0x100);
}
