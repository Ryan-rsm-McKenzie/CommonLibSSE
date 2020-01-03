#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSOpenCloseForm.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESContainer.h"
#include "RE/TESFullName.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	struct CONT_DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kAllowsSoundsWhenAnimation = 1 << 0,
			kRespawn = 1 << 1,
			kShowOwner = 1 << 2
		};


		Flag flags;	// 0
	};
	STATIC_ASSERT(sizeof(CONT_DATA) == 0x1);


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


		virtual ~TESObjectCONT();																															// 00
		
		// override (TESBoundAnimObject)
		virtual void	InitializeData() override;																											// 04
		virtual bool	Load(TESFile* a_mod) override;																										// 06
		virtual void	InitItemImpl() override;																											// 13
		virtual bool	Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																	// 4C
		virtual void	Unk_4D(void) override;																												// 4D


		// members
		UInt8					unkB8;		// B8
		CONT_DATA				data;		// B9 - DATA
		UInt16					padBA;		// BA
		UInt32					padBC;		// BC
		BGSSoundDescriptorForm*	openSound;	// C0 - SNAM
		BGSSoundDescriptorForm*	closeSound;	// C8 - QNAM
	};
	STATIC_ASSERT(sizeof(TESObjectCONT) == 0xD0);
}
