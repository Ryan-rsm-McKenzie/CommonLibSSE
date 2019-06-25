#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectSTAT

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class TESObjectSTAT :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectSTAT;


		enum { kTypeID = FormType::Static };


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


		struct DirectionalMaterial	// DNAM
		{
			enum class Flag : UInt32
			{
				kNone = 0
			};


			float				maxAngle;	// 00 - (30 - 120)
			UInt32				pad04;		// 04
			BGSMaterialObject*	material;	// 08
			Flag				flags;		// 10
			UInt32				pad14;		// 14
		};
		STATIC_ASSERT(sizeof(DirectionalMaterial) == 0x18);


		virtual ~TESObjectSTAT();							// 00

		// override (TESBoundObject)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
		virtual bool	IsPlayable() override;				// 19 - { return true; }
		virtual bool	NeverFades() override;				// 1A - { return (flags >> 2) & 1; }


		// members
		DirectionalMaterial directionalMaterial;	// 68 - DNAM
	};
	STATIC_ASSERT(sizeof(TESObjectSTAT) == 0x80);
}
