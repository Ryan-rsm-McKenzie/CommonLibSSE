#pragma once

#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESPackage : public TESForm
	{
	public:
		enum { kTypeID = FormType::Package };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct PackData	// PKDT
		{
			enum class Type : UInt8
			{
				kPackage = 18,
				kPackageTemplate = 19
			};


			enum class InterruptOverride
			{
				kNone = 0,
				kSpectator = 1,
				kObserveDead = 2,
				kGuardWarn = 3,
				kCombat = 4
			};


			enum class PreferredSpeed : UInt8
			{
				kWalk = 0,
				kJog = 1,
				kRun = 2,
				kFastWalk = 3
			};


			enum class InterruptFlag : UInt16
			{
				kNone = 0,
				kHellosToPlayer = 1 << 0,
				kRandomConversations = 1 << 1,
				kObserveCombatBehaviour = 1 << 2,
				kGreetCorpseBehaviour = 1 << 3,
				kReactionToPlayerActions = 1 << 4,
				kFriendlyFireComments = 1 << 5,
				kAggroRadiusBehavior = 1 << 6,
				kAllowIdleChatter = 1 << 7,
				kWorldInteractions = 1 << 9
			};


			UInt32			unk00;			// 00
			Type			type;			// 04
			UInt8			unk05;			// 05
			PreferredSpeed	preferredSpeed;	// 06
			UInt8			unk07;			// 07
			InterruptFlag	interruptFlags;	// 08
			UInt16			unk0A;			// 0A
			UInt32			unk0C;			// 0C
		};
		STATIC_ASSERT(sizeof(PackData) == 0x10);


		struct Schedule	// PSDT
		{
			enum class DayOfWeek : SInt8
			{
				kAny = -1,
				kSunday = 0,
				kMonday = 1,
				kTuesday = 2,
				kWednesday = 3,
				kThursday = 4,
				kFriday = 5,
				kSaturday = 6,
				kWeekdays = 7,
				kWeekends = 8,
				kMondayWednesdayFriday = 9,
				kTuesdayThursday = 10
			};


			SInt8		month;		// 0
			DayOfWeek	dayOfWeek;	// 1
			SInt8		date;		// 2
			SInt8		hour;		// 3
			SInt8		minute;		// 4
			UInt8		unk0;		// 5
			UInt8		unk0;		// 6
			UInt8		unk0;		// 7
		};
		STATIC_ASSERT(sizeof(Schedule) == 0x8);


		virtual ~TESPackage();												// 00

		// override (TESForm)
		virtual void		InitDefaults() override;						// 04
		virtual void		Unk_05(void) override;							// 05
		virtual bool		LoadForm(TESFile* a_mod) override;				// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void		Unk_12(void) override;							// 12
		virtual void		InitItem() override;							// 13
		virtual void		Unk_2D(void) override;							// 2D - { return unkDC; }
		virtual const char*	GetTypeString() const override;					// 39 - { return g_packageTypeStrings[unk24]; }

		// add
		virtual void		Unk_3B(void);									// 3B
		virtual void		Unk_3C(void);									// 3C
		virtual void		Unk_3D(void);									// 3D
		virtual void		Unk_3E(void);									// 3E
		virtual void		Unk_3F(void);									// 3F - { return 1; }


		// members
		PackData	packData;	// 20 - PKDT
		UInt64		unk30;		// 30
		UInt64		unk38;		// 38
		UInt64		unk40;		// 40
		UInt64		unk48;		// 48
		Schedule	schedule;	// 50 - PSDT
		UInt64		unk58;		// 58
		Condition	conditions;	// 60
		UInt64		unk68;		// 68
		UInt64		unk70;		// 70
		UInt64		unk78;		// 78
		UInt64		unk80;		// 80
		UInt64		unk88;		// 88
		UInt64		unk90;		// 90
		UInt64		unk98;		// 98
		UInt64		unkA0;		// A0
		UInt64		unkA8;		// A8
		UInt64		unkB0;		// B0
		UInt64		unkB8;		// B8
		UInt64		unkC0;		// C0
		UInt64		unkC8;		// C8
		UInt64		unkD0;		// D0
		UInt64		unkD8;		// D8
	};
	STATIC_ASSERT(sizeof(TESPackage) == 0xE0);
}
