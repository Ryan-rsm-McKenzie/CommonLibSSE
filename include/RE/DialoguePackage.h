#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/FormTypes.h"
#include "RE/TESPackage.h"


namespace RE
{
	class DialoguePackage : public TESPackage
	{
	public:
		inline static constexpr auto RTTI = RTTI_DialoguePackage;
		inline static constexpr auto FORMTYPE = FormType::Package;


		virtual ~DialoguePackage();	 // 00

		// override (TESPackage)
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;	   // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;	   // 0F
		virtual void InitLoadGame(BGSLoadFormBuffer* a_buf) override;  // 10 - { TESForm::InitLoadGame(a_buf); }
		virtual void Copy(TESForm* a_srcForm) override;				   // 2F - { TESForm::Copy(a_srcForm); }
		virtual bool IsPackageOwner(Actor* a_actor) override;		   // 3F


		// members
		UInt32			unk0E0;	 // 0E0
		ObjectRefHandle unk0E4;	 // 0E4
		ActorHandle		unk0E8;	 // 0E8
		ActorHandle		unk0EC;	 // 0EC
		UInt64			unk0F0;	 // 0F0
		UInt64			unk0F8;	 // 0F8
	};
	STATIC_ASSERT(sizeof(DialoguePackage) == 0x100);
}
