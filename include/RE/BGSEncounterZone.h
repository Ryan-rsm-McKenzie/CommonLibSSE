#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSEncounterZone

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSEncounterZone : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSEncounterZone;


		enum { kTypeID = FormType::EncounterZone };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kNeverResets = 1 << 0,
				kMatchPCBelowMinimumLevel = 1 << 1,
				kDisableCombatBoundary = 1 << 2
			};


			TESFaction*		owner;		// 00
			BGSLocation*	location;	// 08
			UInt8			rank;		// 10
			UInt8			minLevel;	// 11
			Flag			flags;		// 12
			UInt8			maxLevel;	// 13
			UInt32			unk14;		// 14
		};
		STATIC_ASSERT(sizeof(Data) == 0x18);


		virtual ~BGSEncounterZone();									// 00

		// override (TESForm)
		virtual void	InitDefaults() override;						// 04
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13


		// members
		Data	data;	// 20 - DATA
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
	};
	STATIC_ASSERT(sizeof(BGSEncounterZone) == 0x48);
}
