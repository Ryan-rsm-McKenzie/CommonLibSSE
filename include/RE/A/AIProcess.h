#pragma once

#include "RE/A/ActorPackage.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"

namespace RE
{
	enum class RESET_3D_FLAGS;
	class Actor;
	class bhkCharacterController;
	class HighProcess;
	class TESForm;
	struct HighProcessData;
	struct MiddleHighProcessData;

	enum class PROCESS_TYPE
	{
		kNone = static_cast<std::underlying_type_t<PROCESS_TYPE>>(-1),
		kHigh = 0,
		kMiddleHigh = 1,
		kMiddleLow = 2,
		kLow = 3
	};

	class MiddleLowProcessData
	{
	public:
		// members
		std::int32_t hourPackageEvaluated;	// 0
	};
	static_assert(sizeof(MiddleLowProcessData) == 0x4);

	struct CachedValueData
	{
	public:
		// members
		bool		  dirty;  // 0
		std::uint8_t  pad1;	  // 1
		std::uint16_t pad2;	  // 2
		float		  value;  // 4
	};
	static_assert(sizeof(CachedValueData) == 0x8);

	struct CachedValues
	{
	public:
		enum class Flags
		{
			kNone = 0,
			kRadius = 1 << 0,
			kWidth = 1 << 1,
			kLength = 1 << 2,
			kDPS = 1 << 3,
			kMedicineEffectivenessMult = 1 << 4,
			kEyeLevel = 1 << 9,
			kConditionPreventsRun = 1 << 10,
			kForwardLength = 1 << 11,
			kActorIsGhost = 1 << 20,
			kHealthDamaged = 1 << 21,
			kMagickaPointsDamaged = 1 << 22,
			kStaminaDamaged = 1 << 23,
			kOwnerIsNPC = 1 << 25,
			kOwnerIsUndead = 1 << 26,
			kOwnerIsInCombatantFaction = 1 << 27
		};

		enum class BooleanValue
		{
			kNone = 0,
			kConditionPreventsRun = 1 << 0,
			kOwnerIsNPC = 1 << 1,
			kOwnerIsUndead = 1 << 2,
			kOwnerIsInCombatantFaction = 1 << 3
		};

		float										  cachedRadius;				 // 00
		float										  cachedWidth;				 // 04
		float										  cachedLength;				 // 08
		float										  cachedForwardLength;		 // 0C
		float										  cachedDPS;				 // 10
		float										  cachedEyeLevel;			 // 14
		float										  cachedWalkSpeed;			 // 18
		float										  cachedRunSpeed;			 // 1C
		float										  cachedJogSpeed;			 // 20
		float										  cachedFastWalkSpeed;		 // 24
		stl::enumeration<BooleanValue, std::uint32_t> booleanValues;			 // 28
		stl::enumeration<Flags, std::uint32_t>		  flags;					 // 2C
		BSTArray<CachedValueData>					  actorValueCache;			 // 30
		BSTArray<CachedValueData>					  permanentActorValueCache;	 // 48
	};
	static_assert(sizeof(CachedValues) == 0x60);

	struct ObjectstoAcquire
	{
	public:
		// members
		std::uint64_t unk00;  // 00
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
	};
	static_assert(sizeof(ObjectstoAcquire) == 0x28);

	class AIProcess
	{
	public:
		enum class LowProcessFlags : std::uint8_t
		{
			kNone = 0,
			kAlert = 1 << 3,
		};

		struct Hands
		{
			enum Hand : std::uint32_t
			{
				kLeft,
				kRight,
				kTotal
			};
		};
		using Hand = Hands::Hand;

		struct Data0B8
		{
		public:
			// members
			void*		  unk00;  // 00
			Data0B8*	  unk08;  // 08
			void*		  unk10;  // 10
			void*		  unk18;  // 18
			std::uint64_t unk20;  // 20
			void*		  unk28;  // 28
			std::uint32_t unk30;  // 30
			std::uint32_t pad34;  // 34
		};
		static_assert(sizeof(Data0B8) == 0x38);

		float					GetCachedHeight() const;
		bhkCharacterController* GetCharController();
		ActorHandle				GetCommandingActor() const;
		TESForm*				GetEquippedLeftHand();
		TESForm*				GetEquippedRightHand();
		[[nodiscard]] bool		GetIsSummonedCreature() const noexcept;
		ObjectRefHandle			GetOccupiedFurniture() const;
		bool					InHighProcess() const;
		bool					InMiddleHighProcess() const;
		bool					InMiddleLowProcess() const;
		bool					InLowProcess() const;
		bool					IsArrested() const;
		bool					IsGhost() const;
		void					SetArrested(bool a_arrested);
		void					SetCachedHeight(float a_height);
		void					Set3DUpdateFlag(RESET_3D_FLAGS a_flags);
		void					Update3DModel(Actor* a_actor);

		// members
		MiddleLowProcessData*							middleLow;						// 000
		MiddleHighProcessData*							middleHigh;						// 008
		HighProcessData*								high;							// 010
		ActorPackage									currentPackage;					// 018
		float											unk048;							// 048
		std::uint32_t									unk04C;							// 04C
		CachedValues*									cachedValues;					// 050
		std::int32_t									numberItemsActivate;			// 058
		std::uint32_t									pad05C;							// 05C
		BSSimpleList<ObjectstoAcquire*>					objects;						// 060
		BSSimpleList<TESObjectREFR*>					genericLocations;				// 070
		ObjectstoAcquire*								acquireObject;					// 080
		ObjectstoAcquire*								savedAcquireObject;				// 088
		float											essentialDownTimer;				// 090
		float											deathTime;						// 094
		float											trackedDamage;					// 098
		std::uint32_t									pad09C;							// 09C
		BSTArray<TESForm*>								forms;							// 0A0
		Data0B8											unk0B8;							// 0B8
		TESForm*										equippedObjects[Hand::kTotal];	// 0F0
		std::uint64_t									unk100;							// 100
		std::uint64_t									unk108;							// 108
		std::uint32_t									unk110;							// 110
		RefHandle										target;							// 114
		std::uint64_t									unk118;							// 118
		std::uint64_t									unk120;							// 120
		std::uint64_t									unk128;							// 128
		std::uint32_t									unk130;							// 130
		std::uint16_t									unk134;							// 134
		stl::enumeration<LowProcessFlags, std::uint8_t> lowProcessFlags;				// 136
		stl::enumeration<PROCESS_TYPE, std::uint8_t>	processLevel;					// 137
		bool											skippedTimeStampForPathing;		// 138
		bool											ignoringCombat;					// 139
		bool											endAlarmOnActor;				// 13A
		bool											escortingPlayer;				// 13B
		std::uint32_t									pad13C;							// 13C

	protected:
		void Update3DModel_Impl(Actor* a_actor);
	};
	static_assert(sizeof(AIProcess) == 0x140);
}
