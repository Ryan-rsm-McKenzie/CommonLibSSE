#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	struct TESObjectSTATData  // DNAM
	{
		enum class Flag : UInt32
		{
			kNone = 0
		};


		float			   materialThresholdAngle;	// 00 - (30 - 120)
		UInt32			   pad04;					// 04
		BGSMaterialObject* materialObj;				// 08
		Flag			   flags;					// 10
		UInt32			   pad14;					// 14
	};
	STATIC_ASSERT(sizeof(TESObjectSTATData) == 0x18);


	class TESObjectSTAT :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectSTAT;
		inline static constexpr auto FORMTYPE = FormType::Static;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNeverFades = 1 << 2,
				kDeleted = 1 << 5,
				kHasTreeLOD = 1 << 6,
				kAddOnLODObject = 1 << 7,
				kHiddenFromLocalMap = 1 << 9,
				kHasDistantLOD = 1 << 15,
				kUsesHDLODTexture = 1 << 17,
				kHasCurrents = 1 << 19,
				kIsMarker = 1 << 23,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kShowInWorldMap = 1 << 28,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};


		virtual ~TESObjectSTAT();  // 00

		// override (TESBoundObject)
		virtual void ClearData() override;				// 05
		virtual bool Load(TESFile* a_mod) override;		// 06
		virtual void InitItemImpl() override;			// 13
		virtual bool GetPlayable() const override;		// 19 - { return true; }
		virtual bool IsHeadingMarker() const override;	// 1A - { return (flags >> 2) & 1; }

		bool HasTreeLOD() const;


		// members
		TESObjectSTATData data;	 // 68 - DNAM
	};
	STATIC_ASSERT(sizeof(TESObjectSTAT) == 0x80);
}
