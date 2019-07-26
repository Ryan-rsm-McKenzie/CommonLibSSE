#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectCONT

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSOpenCloseForm.h"  // BGSOpenCloseForm
#include "RE/FormTypes.h"  // FormType, BGSSoundDescriptorForm
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESContainer.h"  // TESContainer
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESObjectCONT :
		public TESBoundAnimObject,			// 00
		public TESContainer,				// 30
		public TESFullName,					// 48
		public TESModelTextureSwap,			// 58
		public TESWeightForm,				// 90
		public BGSDestructibleObjectForm,	// A0
		public BGSOpenCloseForm				// B0
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectCONT;


		enum { kTypeID = FormType::Container };


		enum class Flag : UInt8
		{
			kNone = 0,
			kAllowsSoundsWhenAnimation = 1 << 0,
			kRespawns = 1 << 1,
			kShowOwner = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};


		virtual ~TESObjectCONT();																																	// 00

		// override (TESBoundAnimObject)
		virtual void	InitDefaults();																																// 04
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	InitItem() override;																														// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4C
		virtual void	Unk_4D(void) override;																														// 4D


		// members
		UInt8					unkB8;		// B8
		Flag					flags;		// B9 - DATA
		UInt16					unkBA;		// BA
		UInt32					unkBC;		// BC
		BGSSoundDescriptorForm*	openSound;	// C0 - SNAM
		BGSSoundDescriptorForm*	closeSound;	// C8 - QNAM
	};
	STATIC_ASSERT(sizeof(TESObjectCONT) == 0xD0);
}
