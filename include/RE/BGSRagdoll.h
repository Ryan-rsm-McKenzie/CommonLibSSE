#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSRagdoll

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class TESActorBase;


	class BGSRagdoll :
		public TESForm,	// 000
		public TESModel	// 020
	{
	public:
		inline static const void* RTTI = RTTI_BGSRagdoll;


		enum { kTypeID = FormType::Ragdoll };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSRagdoll();								// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		UInt64				unk048;	// 048
		UInt64				unk050;	// 050
		UInt64				unk058;	// 058
		UInt64				unk060;	// 060
		UInt64				unk068;	// 068
		UInt64				unk070;	// 070
		UInt64				unk078;	// 078
		UInt64				unk080;	// 080
		UInt64				unk088;	// 088
		UInt64				unk090;	// 090
		BSTArray<void*>		unk098;	// 098
		UInt64				unk0B0;	// 0B0
		UInt64				unk0B8;	// 0B8
		UInt64				unk0C0;	// 0C0
		UInt64				unk0C8;	// 0C8
		BSTArray<void*>		unk0D0;	// 0D0
		BSTArray<void*>		unk0E8;	// 0E8
		UInt64				unk100;	// 100
		BSTArray<void*>		unk108;	// 108
		BSTArray<void*>		unk120;	// 120
		UInt64				unk138;	// 138
		BSTArray<void*>		unk140;	// 140
		BSTArray<void*>		unk158;	// 158
		UInt64				unk170;	// 170
		UInt64				unk178;	// 178
		UInt64				unk180;	// 180
		UInt64				unk188;	// 188
		UInt64				unk190;	// 190
		UInt64				unk198;	// 198
		UInt64				unk1A0;	// 1A0
		BGSBodyPartData*	unk1A8;	// 1A8
		TESActorBase*		unk1B0;	// 1B0
	};
	STATIC_ASSERT(sizeof(BGSRagdoll) == 0x1B8);
}
