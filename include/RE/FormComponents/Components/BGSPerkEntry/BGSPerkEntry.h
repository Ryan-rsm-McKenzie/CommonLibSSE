#pragma once

#include "RE/FormComponents/Components/BGSEntryPoint.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	class Actor;
	class BGSEntryPointFunctionData;
	class TESFile;


	enum class PERK_ENTRY_TYPE : UInt32
	{
		kQuest = 0,
		kAbility = 1,
		kEntryPoint = 2
	};


	class BGSPerkEntry
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPerkEntry;


		using EntryPoint = BGSEntryPoint::ENTRY_POINT;


		struct Header  // PRKE
		{
		public:
			// members
			UInt8  rank;	  // 0
			UInt8  priority;  // 1
			UInt16 unk2;	  // 2
			UInt32 unk4;	  // 4
		};
		STATIC_ASSERT(sizeof(Header) == 0x8);


		virtual bool	   CheckConditionFilters(UInt32 a_numArgs, void* a_args);  // 00 - { return false; }
		virtual EntryPoint GetFunction();										   // 01 - { return 0; }
		virtual void*	   GetFunctionData() const;								   // 02 - { return 0; }

		virtual ~BGSPerkEntry();  // 03

		virtual PERK_ENTRY_TYPE GetType() const = 0;				  // 04
		virtual void			ClearData();						  // 05 - { return; }
		virtual void			InitItem(TESFile* a_owner);			  // 06 - { return; }
		virtual bool			Load(TESFile* a_file);				  // 07 - { return true; }
		virtual void			SetParent(BGSPerk* a_parent);		  // 08 - { return; }
		virtual UInt16			GetID() const;						  // 09 - { return 0xFFFF; }
		virtual void			ApplyPerkEntry(Actor* a_actor) = 0;	  // 0A
		virtual void			RemovePerkEntry(Actor* a_actor) = 0;  // 0B

		UInt8 GetRank() const;
		UInt8 GetPriority() const;


		// members
		Header header;	// 08 - PRKE
	};
	STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x10);
}
