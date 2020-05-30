#pragma once

#include "RE/BGSEntryPoint.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSEntryPointFunctionData;
	class TESFile;


	class BGSPerkEntry
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPerkEntry;


		using EntryPoint = BGSEntryPoint::ENTRY_POINT;


		enum class Type
		{
			kQuestStage = 0,
			kAbility = 1,
			kEntryPoint = 2
		};


		struct Header  // PRKE
		{
			UInt8  rank;	  // 0
			UInt8  priority;  // 1
			UInt16 unk2;	  // 2
			UInt32 unk4;	  // 4
		};
		STATIC_ASSERT(sizeof(Header) == 0x8);


		virtual bool					   EvaluateConditions(UInt32 a_numArgs, void* a_args);	// 00 - { return false; }
		virtual EntryPoint				   GetEntryPoint() const;								// 01 - { return 0; }
		virtual BGSEntryPointFunctionData* GetFunctionData() const;								// 02 - { return 0; }

		virtual ~BGSPerkEntry();  // 03

		virtual Type GetType() const = 0;			// 04
		virtual void ReleaseRefs();					// 05 - { return; }
		virtual void ResolveForms(TESFile* a_mod);	// 06 - { return; }
		virtual bool LoadPerk(TESFile* a_mod);		// 07 - { return true; }
		virtual void SetPerk(BGSPerk* a_perk);		// 08 - { return; }
		virtual void Unk_09(void);					// 09 - { return 0xFFFF; }
		virtual void Unk_0A(void) = 0;				// 0A
		virtual void Unk_0B(void) = 0;				// 0B

		UInt8 GetRank() const;
		UInt8 GetPriority() const;


		// members
		Header header;	// 08 - PRKE
	};
	STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x10);
}
