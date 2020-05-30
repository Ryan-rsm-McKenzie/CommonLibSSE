#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/FormTypes.h"
#include "RE/TESFullName.h"
#include "RE/TESObjectSTAT.h"


namespace RE
{
	struct MOVABLE_STATIC_DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kOnLocalMap = 1 << 0
		};


		Flag flags;	 // 0
	};
	STATIC_ASSERT(sizeof(MOVABLE_STATIC_DATA) == 0x1);


	class BGSMovableStatic :
		public TESFullName,				   // 00
		public BGSDestructibleObjectForm,  // 10
		public TESObjectSTAT			   // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMovableStatic;
		inline static constexpr auto FORMTYPE = FormType::MovableStatic;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kMustUpdateAnims = 1 << 8,
				kHiddenFromLocalMap = 1 << 9,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kHasCurrents = 1 << 19,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};


		virtual ~BGSMovableStatic();  // 00

		// override (TESObjectSTAT)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSSoundDescriptorForm* soundLoop;	// A0 - SNAM
		MOVABLE_STATIC_DATA		data;		// A8
		UInt8					padA9;		// A9
		UInt16					padAA;		// AA
		UInt32					padAC;		// AC
	};
	STATIC_ASSERT(sizeof(BGSMovableStatic) == 0xB0);
}
