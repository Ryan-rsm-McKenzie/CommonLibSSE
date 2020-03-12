#pragma once

#include "RE/ActorValues.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESObjectACTI.h"


namespace RE
{
	class TESFurniture : public TESObjectACTI
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESFurniture;
		inline static constexpr auto FORMTYPE = FormType::Furniture;


		enum class ActiveMarker : UInt32
		{
			kNone = 0,
			kSit0 = 1 << 0,
			kSit1 = 1 << 1,
			kSit2 = 1 << 2,
			kSit3 = 1 << 3,
			kSit4 = 1 << 4,
			kSit5 = 1 << 5,
			kSit6 = 1 << 6,
			kSit7 = 1 << 7,
			kSit8 = 1 << 8,
			kSit9 = 1 << 9,
			kSit10 = 1 << 10,
			kSit11 = 1 << 11,
			kSit12 = 1 << 12,
			kSit13 = 1 << 13,
			kSit14 = 1 << 14,
			kSit15 = 1 << 15,
			kSit16 = 1 << 16,
			kSit17 = 1 << 17,
			kSit18 = 1 << 18,
			kSit19 = 1 << 19,
			kSit20 = 1 << 20,
			kSit21 = 1 << 21,
			kSit22 = 1 << 22,
			kSit23 = 1 << 23,
			kDisablesActivation = 1 << 25,
			kIsPerch = 1 << 26,
			kMustExitToTalk = 1 << 27
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIsPerch = 1 << 7,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kIsMarker = 1 << 23,
				kMustExitToTalk = 1 << 28,
				kChildCanUse = 1 << 29
			};
		};


		struct WorkBenchData  // WBDT
		{
			enum class BenchType : UInt8
			{
				kNone = 0,
				kCreateObject = 1,
				kSmithingWeapon = 2,
				kEnchanting = 3,
				kEnchantingExperiment = 4,
				kAlchemy = 5,
				kAlchemyExperiment = 6,
				kSmithingArmor = 7,
			};


			BenchType	benchType;	// 0
			ActorValue8 usesSkill;	// 1
		};
		STATIC_ASSERT(sizeof(WorkBenchData) == 0x2);


		struct EntryPointData
		{
			struct DisabledEntryPoint  // NAM0
			{
				enum class DisabledPoint : UInt16
				{
					kNone = 0,
					kFront = 1 << 0,
					kBehind = 1 << 1,
					kRight = 1 << 2,
					kLeft = 1 << 3,
					kUp = 1 << 4
				};


				UInt16		  unk0;			   // 0
				DisabledPoint disabledPoints;  // 2
			};
			STATIC_ASSERT(sizeof(DisabledEntryPoint) == 0x4);


			UInt32			   entryPoint;			 // 00 - ENAM
			DisabledEntryPoint disabledEntryPoints;	 // 04 - NAM0
			BGSKeyword*		   keyword;				 // 08 - FNMK
		};
		STATIC_ASSERT(sizeof(EntryPointData) == 0x10);


		virtual ~TESFurniture();  // 00

		// override (TESObjectACTI)
		virtual void		InitializeData() override;																													 // 04
		virtual void		ClearData() override;																														 // 05
		virtual bool		Load(TESFile* a_mod) override;																												 // 06
		virtual void		InitItemImpl() override;																													 // 13
		virtual bool		Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;	 // 37
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref) override;																										 // 4A
		virtual bool		GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																		 // 4C
		virtual bool		CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;										 // 4D


		// members
		BSTArray<EntryPointData> entryPointDataArray;  // C8
		WorkBenchData			 workBenchData;		   // E0 - WBDT
		UInt16					 padE2;				   // E2
		ActiveMarker			 furnFlags;			   // E4
		SpellItem*				 associatedForm;	   // E8
	};
	STATIC_ASSERT(sizeof(TESFurniture) == 0xF0);
}
